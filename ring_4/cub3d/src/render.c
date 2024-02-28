/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:59:50 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/28 20:26:01 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
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

void	ft_floor_ceiling(t_data *data, int ray, int t_pix, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < S_H)
		ft_pixel_put(data, ray, i++, ft_get_rgba(128, 128, 128, 255));
	i = 0;
	while (i < t_pix)
		ft_pixel_put(data, ray, i++, ft_get_rgba(137, 207, 243, 255));
}

int	ft_color(t_data *data, int flag)
{
	data->ray->angle = ft_normalized(data->ray->angle);
	if (flag == 0)
	{
		if (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * (M_PI / 2))
			return (ft_get_rgba(181, 181, 181, 255)); // west
		else
			return (ft_get_rgba(181, 181, 181, 255)); // east
	}
	else
	{
		if (data->ray->angle > 0 && data->ray->angle < M_PI)
			return (ft_get_rgba(245, 245, 245, 255)); // south
		else
			return (ft_get_rgba(245, 245, 245, 255)); // north
	}
}

void	ft_wall(t_data *data, int ray, int t_pix, int b_pix)
{
	//int	pixel;
	int	color;

	color = ft_color(data, data->ray->flag);
	while (t_pix < b_pix)
	{
		//pixel = ((TILE_SIZE * TILE_SIZE) - TILE_SIZE + t_pix) * 4;
		//color = ft_get_color(data->wall->north, pixel);
		ft_pixel_put(data, ray, t_pix++, color);
	}
}

void	ft_render(t_data *data, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;

	data->ray->distance *= cos(ft_normalized(data->ray->angle - data->ply->angle)); //too long line!!!
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
