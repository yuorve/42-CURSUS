/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:41:38 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/06 19:39:37 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

mlx_image_t	*ft_load_bricks(t_data *data)
{
	mlx_image_t		*wall;
	mlx_texture_t	*png;

	png = mlx_load_png("assets/bricksx64.png");
	wall = mlx_texture_to_image(data->mlx, png);
	mlx_delete_texture(png);
	return (wall);
}

mlx_image_t	*ft_load_image(t_data *data, int c)
{
	int				i;
	int				line;
	int				pixel;
	mlx_image_t		*wall;
	mlx_texture_t	*png;

	png = mlx_load_png("assets/walls.png");
	wall = mlx_new_image(data->mlx, TEXTURE, TEXTURE);
	line = 0;
	i = 0;
	while (i < (TEXTURE * TEXTURE * 4))
	{
		pixel = ((TEXTURE * 4) * c);
		while (pixel < ((TEXTURE * 4) * (c + 1)))
		{
			wall->pixels[i] = png->pixels[pixel + line];
			pixel++;
			i++;
		}
		line += (TEXTURE * 6 * 4);
	}
	mlx_delete_texture(png);
	return (wall);
}

void	ft_load_texture(t_data *data)
{
	data->wall->north = ft_load_bricks(data);
	//data->wall->north = ft_load_image(data, 0);
	data->wall->south = ft_load_image(data, 1);
	data->wall->east = ft_load_image(data, 5);
	data->wall->west = ft_load_image(data, 0);
}

int	ft_get_color(mlx_image_t *img, int pixel)
{
	int	tmp;

	tmp = img->pixels[pixel] << 24 | img->pixels[pixel + 1] << 16
		| img->pixels[pixel + 2] << 8 | img->pixels[pixel + 3];
	return (tmp);
}

int	ft_load_pixel(mlx_image_t *wall, int pixel)
{
	return (wall->pixels[pixel]);
}
