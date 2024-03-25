/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:38 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/25 17:47:04 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

mlx_texture_t	*ft_load_bricks(int c)
{
	mlx_texture_t	*png;

	if (c == 1)
		png = mlx_load_png("assets/north.png");
	else if (c == 2)
		png = mlx_load_png("assets/south.png");
	else if (c == 3)
		png = mlx_load_png("assets/east.png");
	else
		png = mlx_load_png("assets/west.png");
	return (png);
}

void	ft_load_texture(t_data *data)
{
	data->wall->north = mlx_load_png(data->structure->no);
	data->wall->south = mlx_load_png(data->structure->so);
	data->wall->east = mlx_load_png(data->structure->ea);
	data->wall->west = mlx_load_png(data->structure->we);
}

int	ft_get_color(int pixel)
{
	unsigned int	tmp;

	tmp = (pixel & 0xFF) << 24 | (pixel & 0xFF00) << 8
		| (pixel & 0xFF0000) >> 8 | (pixel & 0xFF000000) >> 24;
	return (tmp);
}

void	ft_floor_ceiling(t_data *data, int ray, int t_pix, int b_pix)
{
	int	i;

	i = b_pix;
	while (i < S_H)
		ft_pixel_put(data, ray, i++, data->structure->c);
	i = 0;
	while (i < t_pix)
		ft_pixel_put(data, ray, i++, data->structure->f);
}
