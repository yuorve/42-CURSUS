/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:43:37 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/06 19:50:09 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	load_content(t_data *data, int j, int i)
{
	if (data->map[j][i] == 'C')
		data->keys++;
	else if (data->map[j][i] == 'M')
	{
		data->enemy++;
		data->enemy_pos.y = j;
		data->enemy_pos.x = i;
		data->map[j][i] = '0';
	}
	else if (data->map[j][i] == 'E')
	{
		data->exit++;
		data->exit_pos.y = j;
		data->exit_pos.x = i;
	}
	else if (data->map[j][i] == 'P')
	{
		data->player++;
		data->player_pos.y = j;
		data->player_pos.x = i;
	}
}

void	content_checks(t_data *data)
{
	size_t		i;
	size_t		j;

	j = -1;
	while (++j < data->map_height)
	{
		i = -1;
		while (++i < data->map_width)
		{
			load_content(data, j, i);
		}
	}
	if (data->player != 1)
		quit(data, "Error file structure one player is needed");
	if (data->enemy != 1)
		quit(data, "Error file structure one enemy is needed");
}

void	map_checks(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (data->map[j][i] != '\n')
	{
		if (data->map[j][i++] != '1')
			quit(data, "Error file structure missing walls.");
	}
	while (data->map[data->map_height - 1][--i])
	{
		if (data->map[data->map_height - 1][i] != '1')
			quit(data, "Error file structure missing walls..");
	}
	while (data->map[++j] != NULL)
	{
		if (data->map[j][ft_strlen(data->map[j]) - 1] == '\n')
		{
			if (data->map_width != ft_strlen(data->map[j]) - 1)
				quit(data, "Error file structure sizes.");
		}
		if (data->map[j][0] != '1' && data->map[j][data->map_width - 1] != '1')
			quit(data, "Error file structure missing walls...");
	}
}

void	map_sizes(t_data *data)
{
	int		fd;
	char	*str;

	fd = open(data->file, O_RDONLY);
	if (fd < 0)
		quit(data, "Error opening file.");
	str = get_next_line(fd);
	data->map_width = ft_strlen(str) - 1;
	while (str != NULL)
	{
		if (str[ft_strlen(str) - 1] == '\n')
		{
			if (data->map_width != ft_strlen(str) - 1)
				quit(data, "Error file structure sizes..");
		}
		else
		{
			if (data->map_width != ft_strlen(str))
				quit(data, "Error file structure sizes...");
		}
		data->map_height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	reading(t_data *data)
{
	int		fd;
	int		i;
	char	**matrix;

	fd = open(data->file, O_RDONLY);
	if (fd < 0)
		quit(data, "Error opening file");
	i = 0;
	map_sizes(data);
	data->map = ft_calloc(data->map_height, data->map_width);
	data->map[i] = get_next_line(fd);
	while (data->map[i++] != NULL)
		data->map[i] = get_next_line(fd);
	close(fd);
	map_checks(data);
	content_checks(data);
	matrix = ft_copy(data->map, data->map_height);
	flood_fill(matrix, data->player_pos);
	if (thisistheway(matrix, data->exit_pos) != 1)
		quit(data, "Error no way out");
	ft_freeplus(matrix, data->map_height);
}
