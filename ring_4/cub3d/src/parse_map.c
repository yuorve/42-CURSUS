/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:02:54 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 16:51:31 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_flood_fill(t_data *data, int y, int x)
{
	if (x < 0 || y < 0 || x >= data->structure->size_x + 2
		|| y >= data->structure->size_y + 2)
		return ;
	if (data->structure->copy_map[y][x] != '1'
		&& data->structure->copy_map[y][x] != '2'
		&& data->structure->copy_map[y][x] != '3'
		&& data->structure->copy_map[y][x] != '\0')
	{
		if (data->structure->copy_map[y][x] == ' ')
			data->structure->copy_map[y][x] = '3';
		else
			data->structure->copy_map[y][x] = '2';
		ft_flood_fill(data, y + 1, x);
		ft_flood_fill(data, y + 1, x + 1);
		ft_flood_fill(data, y + 1, x - 1);
		ft_flood_fill(data, y - 1, x);
		ft_flood_fill(data, y - 1, x + 1);
		ft_flood_fill(data, y - 1, x - 1);
		ft_flood_fill(data, y, x + 1);
		ft_flood_fill(data, y, x - 1);
	}
	ft_check_flood(data);
}

void	ft_check_flood(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->structure->copy_map[y])
	{
		x = 0;
		while (data->structure->copy_map[y][x])
		{
			if (data->structure->copy_map[y][x] == '3')
				exit_error("Invalid walls\n");
			if (!ft_strchr("0NSEW", data->structure->copy_map[y][x]))
				x++;
			else
				break ;
		}
		if (data->structure->copy_map[y][x] == '0')
			ft_flood_fill(data, y, x);
		else
			y++;
	}
}

void	ft_parsing_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->structure->map[y] != NULL)
	{
		x = 0;
		while (data->structure->map[y][x] != '\0')
		{
			if (data->structure->map[y][x] != '\n')
				data->structure->copy_map[y + 1][x + 1]
					= data->structure->map[y][x];
			x++;
		}
		y++;
	}
}

void	ft_copy_map(t_data *data)
{
	int		y;
	int		x;
	char	*line;

	data->structure->copy_map = ft_calloc((data->structure->size_y + 3)
			* sizeof(char), (data->structure->size_x + 3) * sizeof(char));
	line = malloc(sizeof(char) * (data->structure->size_x + 3));
	if (!data->structure->copy_map)
		exit_error("Malloc error\n");
	y = 0;
	while (y < data->structure->size_y + 2)
	{
		x = 0;
		while (x < data->structure->size_x + 1)
			line[x++] = ' ';
		line[x] = '\0';
		data->structure->copy_map[y++] = ft_strdup(line);
	}
	data->structure->copy_map[y] = NULL;
	free(line);
	ft_parsing_map(data);
}
