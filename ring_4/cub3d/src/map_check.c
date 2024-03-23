/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:59:55 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 18:27:41 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_map_param(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == '1' || line[i] == '0') && ft_is_param(line) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_map(t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->map_fd = open(data->map_path, O_RDONLY);
	data->structure->map = (char **)malloc(sizeof(char *)
			* (data->structure->size_y + 1));
	if (!data->structure->map)
		exit_error("Malloc error\n");
	line = get_next_line(data->map_fd);
	while (line)
	{
		if (ft_map_param(line) == 1 && ft_is_param(line) == 0)
		{
			data->structure->map[i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(data->map_fd);
	}
	data->structure->map[i] = NULL;
	close(data->map_fd);
}

void	ft_get_map_size(t_data *data)
{
	char	*line;

	data->map_fd = open(data->map_path, O_RDONLY);
	line = get_next_line(data->map_fd);
	while (line)
	{
		if (ft_map_param(line) == 1 && ft_is_param(line) == 0)
		{
			if (ft_strlen(line) > (size_t)data->structure->size_x)
				data->structure->size_x = ft_strlen(line);
			data->structure->size_y++;
		}
		free(line);
		line = get_next_line(data->map_fd);
	}
	close(data->map_fd);
}

void	ft_validate_map(t_data *data)
{
	ft_copy_map(data);
	ft_check_flood(data);
}
