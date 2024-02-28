/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:38 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/27 21:08:56 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_load_texture(t_data *data)
{
	int				i;
	int				line;
	int				pixel;
	mlx_image_t		*img;
	mlx_texture_t	*png;

	png = mlx_load_png("assets/walls.png");
	data->wall->north = mlx_texture_to_image(data->mlx, png);
	data->wall->south = mlx_texture_to_image(data->mlx, png);
	data->wall->east = mlx_texture_to_image(data->mlx, png);
	data->wall->west = mlx_texture_to_image(data->mlx, png);
	mlx_delete_texture(png);
	img = mlx_new_image(data->mlx, 64, 64);
	line = 1;
	i = 0;
	while (i < 8192)
	{
		pixel = 0;
		while (pixel < 64)
		{
			img->pixels[i] = data->wall->north->pixels[pixel + line];
			pixel++;
			i++;
		}
		line += 384;
	}
	mlx_image_to_window(data->mlx, img, 0, 0);
}
