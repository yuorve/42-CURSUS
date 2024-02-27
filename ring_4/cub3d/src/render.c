/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:59:50 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/27 11:59:50 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void ft_pixel_put(t_data *data, int x, int y, int color)
{
	if (x < 0)
		return ;
	else if (x >= S_W)
		return ;
	if (y < 0)
		return ;
	else if (y >= S_H)
		return ;	
	mlx_put_pixel(data->img, x, y, color);
}

void ft_floor_ceiling(t_data *data, int ray, int t_pix, int b_pix)
{
	int  i;

	i = b_pix;
	while (i < S_H)
		ft_pixel_put(data, ray, i++, 0xB99470FF);
	i = 0;
	while (i < t_pix)
		ft_pixel_put(data, ray, i++, 0x89CFF3FF);
}

int ft_color(t_data *data, int flag)
{
	data->ray->angle = ft_normalized(data->ray->angle);
	if (flag == 0)
	{
		if (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * (M_PI / 2))
			return (0xB5B5B5FF); // west
		else
			return (0xB5B5B5FF); // east
	}
	else
	{
		if (data->ray->angle > 0 && data->ray->angle < M_PI)
			return (0xF5F5F5FF); // south
		else
			return (0xF5F5F5FF); // north
		}
	}

void ft_wall(t_data *data, int ray, int t_pix, int b_pix)
{
	int color;

	color = ft_color(data, data->ray->flag);
	while (t_pix < b_pix)
		ft_pixel_put(data, ray, t_pix++, color);
}

void ft_render(t_data *data, int ray)
{
	double wall_h;
	double b_pix;
	double t_pix;

	data->ray->distance *= cos(ft_normalized(data->ray->angle - data->ply->angle));
	wall_h = (TILE_SIZE / data->ray->distance) * ((S_W / 2) / tan(FOV / 2));
	b_pix = (S_H / 2) + (wall_h / 2);
	t_pix = (S_H / 2) - (wall_h / 2);
	if (b_pix > S_H)
		b_pix = S_H;
	if (t_pix < 0)
		t_pix = 0;
	ft_wall(data, ray, t_pix, b_pix);
	ft_floor_ceiling(data, ray, t_pix, b_pix);
}
