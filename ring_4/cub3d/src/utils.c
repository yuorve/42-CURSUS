/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/31 20:48:58 by yoropeza         ###   ########.fr       */
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

	fd = open(data->mapfile, O_RDONLY);
	if (fd < 0)
		exit(printf("Error Opening file\n"));
	i = 0;
	data->map_height = 500;
	data->map_width = 500;
	data->matrix = ft_calloc(data->map_height, data->map_width);
	data->matrix[i] = get_next_line(fd);
	while (data->matrix[i++] != NULL)
		data->matrix[i] = get_next_line(fd);
	close(fd);
	data->matrix_height = i - 1;
	data->matrix_width = ft_strlen(data->matrix[0]) - 1;
	data->tile_height = data->map_height / data->matrix_height;
	data->tile_width = data->map_width / data->matrix_width;
}

int	ft_collision(t_data *data, int x, int y)
{
	int	res;

	res = 0;
	if (data->matrix[y][x] != '0')
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
