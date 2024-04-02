/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:34:53 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 16:14:51 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_validate_color(char	*c)
{
	size_t	i;

	i = 0;
	if (ft_strlen(c) == 0)
		exit_error("Invalid color\n");
	while (c[i])
	{
		if (!ft_isdigit(c[i]))
			break ;
		i++;
	}
	if (i != ft_strlen(c))
		exit_error("Invalid Color\n");
}

size_t	ft_split_size(char **split)
{
	size_t	size;

	size = 0;
	while (split[size])
		size++;
	return (size);
}

void	ft_free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

int	ft_check_color(char *str)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**rgb;

	i = 0;
	rgb = ft_split(str, ',');
	if (ft_split_size(rgb) != 3)
		exit_error("Invalid color\n");
	rgb[2][ft_strlen(rgb[2]) - 1] = '\0';
	while (rgb[i])
		ft_validate_color(rgb[i++]);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r > 255 || g > 255 || b > 255)
		exit_error("Invalid color\n");
	ft_free_split(rgb);
	return (r << 24 | g << 16 | b << 8 | 255);
}
