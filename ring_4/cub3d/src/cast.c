/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:13:48 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/23 17:51:09 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	ft_hinter(t_data *data, float angl)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = TILE_SIZE;
	x_step = TILE_SIZE / tan(angl);
	h_y = floor(data->ply->pos->y / TILE_SIZE) * TILE_SIZE;
	pixel = ft_inter_check(angl, &h_y, &y_step, 1);
	h_x = data->ply->pos->x + (h_y - data->ply->pos->y) / tan(angl);
	if ((ft_circle(angl, 'y') && x_step > 0)
		|| (!ft_circle(angl, 'y') && x_step < 0))
		x_step *= -1;
	while (ft_wall_hit(h_x, h_y - pixel, data))
	{
		h_x += x_step;
		h_y += y_step;
	}
	data->horiz_x = h_x;
	data->horiz_y = h_y;
	return (ft_pitagoras(h_x, data->ply->pos->x, h_y, data->ply->pos->y));
}

float	ft_vinter(t_data *data, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = TILE_SIZE;
	y_step = TILE_SIZE * tan(angl);
	v_x = floor(data->ply->pos->x / TILE_SIZE) * TILE_SIZE;
	pixel = ft_inter_check(angl, &v_x, &x_step, 0);
	v_y = data->ply->pos->y + (v_x - data->ply->pos->x) * tan(angl);
	if ((ft_circle(angl, 'x') && y_step < 0)
		|| (!ft_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (ft_wall_hit(v_x - pixel, v_y, data))
	{
		v_x += x_step;
		v_y += y_step;
	}
	data->vert_x = v_x;
	data->vert_y = v_y;
	return (ft_pitagoras(v_x, data->ply->pos->x, v_y, data->ply->pos->y));
}

void	ft_raycasting(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = data->ply->pos->x;
	start.y = data->ply->pos->y;
	end.x = start.x + cos(data->ray->angle) * data->ray->distance;
	end.y = start.y + sin(data->ray->angle) * data->ray->distance;
	ft_draw_line_red(start, end, data->ply->img);
}

void	ft_cast_rays(t_data *data)
{
	double	h_inter;
	double	v_inter;
	int		ray;

	ray = 0;
	data->ray->angle = data->ply->angle - (FOV / 2);
	while (ray < S_W)
	{
		data->ray->flag = 0;
		h_inter = ft_hinter(data, ft_normalized(data->ray->angle));
		v_inter = ft_vinter(data, ft_normalized(data->ray->angle));
		if (v_inter <= h_inter)
			data->ray->distance = v_inter;
		else
		{
			data->ray->distance = h_inter;
			data->ray->flag = 1;
		}
		ft_render(data, ray);
		ray++;
		data->ray->angle += (FOV / S_W);
	}
}
