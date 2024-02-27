/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/01 19:38:44 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	read_map(t_data *data)
{
	int		fd;
	int		i;

	fd = open(data->map->file, O_RDONLY);
	if (fd < 0)
		exit(printf("Error Opening file\n"));
	i = 0;
	data->map->width = 10;
	data->map->height = 10;
	data->map->matrix = ft_calloc(data->map->height, data->map->width);
	data->map->matrix[i] = get_next_line(fd);
	while (data->map->matrix[i++] != NULL)
		data->map->matrix[i] = get_next_line(fd);
	close(fd);
}

int	ft_collision(t_data *data, int x, int y)
{
	int	res;

	res = 0;
	if (data->map->matrix[y][x] != '0')
		res = 1;
	return (res);
}

float	ft_normalized(float angle)
{
	float	two_pi;
	float	normalized_angle;

	two_pi = 2 * M_PI;
	normalized_angle = fmod(angle, two_pi);
	if (normalized_angle < 0)
		normalized_angle += two_pi;
	return (normalized_angle);
}

t_point	ft_get_tile(int x, int y)
{
	t_point	tile;

	tile.x = round(x / TILE_SIZE);
	tile.y = round(y / TILE_SIZE);
	return (tile);
}
