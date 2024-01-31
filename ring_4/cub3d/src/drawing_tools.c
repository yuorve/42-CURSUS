/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:58 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/31 20:50:26 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_draw_line(t_point start, t_point end, mlx_image_t *img)
{
	int		e2;
	int		err;
	t_line	line;

	ft_bzero(&line, sizeof(t_line));
	line.dx = abs(end.x - start.x);
	line.dy = abs(end.y - start.y);
	if (start.x < end.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (start.y < end.y)
		line.sy = 1;
	else
		line.sy = -1;
	err = line.dx - line.dy;
	while (1)
	{
		mlx_put_pixel(img, start.x, start.y, 0xFFFFFFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 > -line.dy)
		{
			err -= line.dy;
			start.x += line.sx;
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			start.y += line.sy;
		}
	}
}

void	ft_draw_square(t_point start, t_point end, mlx_image_t *img)
{
	int	i;

	i = start.x;
	end.x += start.x;
	end.y += start.y;
	while (1)
	{
		mlx_put_pixel(img, start.x, start.y, 0xFFFFFFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		else if (start.x == end.x)
		{
			start.y++;
			start.x = i;
		}
		else
			start.x++;
	}
}

void	ft_draw_scene(t_data *data)
{
	int			i;
	int			j;
	mlx_image_t	*wall;
	mlx_image_t	*ground;

	wall = mlx_new_image(data->mlx, data->tile_height, data->tile_width);
	memset(wall->pixels, ft_get_rgba(0, 0, 0, 0), wall->width * wall->height * sizeof(int32_t));
	ground = mlx_new_image(data->mlx, data->tile_height, data->tile_width);
	memset(ground->pixels, ft_get_rgba(102, 102, 102, 102), ground->width * ground->height * sizeof(int32_t));	
	i = -1;	
	while (++i < data->matrix_height)
	{
		j = -1;
		while (++j < data->matrix_width)
		{
			if (data->matrix[i][j] == '1')
				mlx_image_to_window(data->mlx, wall, j * data->tile_width, i * data->tile_height);
			else
				mlx_image_to_window(data->mlx, ground, j * data->tile_width, i * data->tile_height);
		}
	}
}
