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

mlx_texture_t	*ft_load_bricks(int c)
{
	mlx_texture_t	*png;

	if (c == 1)
		png = mlx_load_png("assets/north.png");
	else if (c == 2)
		png = mlx_load_png("assets/south.png");
	else if (c == 3)
		png = mlx_load_png("assets/east.png");
	else if (c == 4)
		png = mlx_load_png("assets/west.png");
	return (png);
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
	//data->wall->north = ft_load_image(data, 0);
	data->wall->north = ft_load_bricks(1);
	data->wall->south = ft_load_bricks(2);
	data->wall->east = ft_load_bricks(3);
	data->wall->west = ft_load_bricks(4);
}

int	ft_get_color(int pixel)
{
	unsigned int	tmp;
	
	tmp = (pixel & 0xFF) << 24 | (pixel & 0xFF00) << 8 
		| (pixel & 0xFF0000) >> 8 | (pixel & 0xFF000000) >> 24;
	return (tmp);	
}

int	ft_load_pixel(mlx_image_t *wall, int pixel)
{
	return (wall->pixels[pixel]);
}
