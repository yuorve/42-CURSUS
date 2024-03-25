/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 11:59:50 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/25 18:01:36 by yoropeza         ###   ########.fr       */
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

double	ft_get_x(mlx_texture_t *texture, t_data *data)
{
	double	x;

	if (data->ray->flag == 1)
		x = (int)fmodf((data->horiz_x * \
		(texture->width / TILE_SIZE)), texture->width);
	else
		x = (int)fmodf((data->vert_y * \
		(texture->width / TILE_SIZE)), texture->width);
	return (x);
}

mlx_texture_t	*ft_texture(t_data *data, int flag)
{
	data->ray->angle = ft_normalized(data->ray->angle);
	if (flag == 0)
	{
		if (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * (M_PI / 2))
			return (data->wall->west);
		else
			return (data->wall->east);
	}
	else
	{
		if (data->ray->angle > 0 && data->ray->angle < M_PI)
			return (data->wall->south);
		else
			return (data->wall->north);
	}
}

void	ft_wall(t_data *data, int ray, int t_pix, int b_pix)
{
	int			color;
	double		t_x;
	double		t_y;
	double		y_step;
	uint32_t	*pixels;

	pixels = data->pixels;
	y_step = (double)data->tex->height / data->wall_h;
	t_x = ft_get_x(data->tex, data);
	t_y = (t_pix - (S_H / 2) + (data->wall_h / 2)) * y_step;
	if (t_y < 0)
		t_y = 0;
	while (t_pix < b_pix)
	{
		color = ft_get_color(pixels[(int)t_y * data->tex->width + (int)t_x]);
		ft_pixel_put(data, ray, t_pix++, color);
		t_y += y_step;
	}
}

void	ft_render(t_data *data, int ray)
{
	double		b_pix;
	double		t_pix;
	double		angle;
	mlx_image_t	*tmp;

	angle = data->ray->angle - data->ply->angle;
	data->ray->distance *= cos(ft_normalized(angle));
	data->wall_h = (TILE_SIZE / data->ray->distance)
		* ((S_W / 2) / tan(FOV / 2));
	b_pix = (S_H / 2) + (data->wall_h / 2);
	t_pix = (S_H / 2) - (data->wall_h / 2);
	if (b_pix > S_H)
		b_pix = S_H;
	if (t_pix < 0)
		t_pix = 0;
	data->tex = ft_texture(data, data->ray->flag);
	tmp = mlx_texture_to_image(data->mlx, data->tex);
	data->pixels = (uint32_t *)tmp->pixels;
	ft_wall(data, ray, t_pix, b_pix);
	ft_floor_ceiling(data, ray, t_pix, b_pix);
	mlx_delete_image(data->mlx, tmp);
}
