/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:34:12 by yoropeza          #+#    #+#             */
/*   Updated: 2023/03/28 19:46:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(const char *str, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			words++;
		i++;
	}
	return (words);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	*get_line(char *line, t_fdf *fdf)
{
	char	**split;
	int		*int_line;
	int		i;

	split = ft_split(line, ' ');
	fdf->width = count_words(line, ' ');
	int_line = malloc(sizeof(int) * fdf->width);
	if (!int_line)
	{
		free_split(split);
		exit_fdf(fdf, EXIT_FAILURE);
	}
	i = 0;
	while (i < fdf->width)
	{
		int_line[i] = ft_atoi(split[i]);
		i++;
	}
	free_split(split);
	return (int_line);
}

static void	read_lines(int fd, t_fdf *fdf)
{
	char	*line;
	int		y;

	y = 0;
	while (get_next_line(fd, &line))
	{
		fdf->height++;
		if (!fdf->map)
			fdf->map = malloc(sizeof(int *) * fdf->height);
		else
			fdf->map = ft_realloc(fdf->map, fdf->height - 1,
					fdf->height, sizeof(int *));
		if (!fdf->map)
			exit_fdf(fdf, EXIT_FAILURE);
		fdf->map[y] = get_line(line, fdf);
		free(line);
		y++;
	}
}

void	read_file(char *file, t_fdf *fdf)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_fdf(fdf, EXIT_FAILURE);
	read_lines(fd, fdf);
	close(fd);
}
