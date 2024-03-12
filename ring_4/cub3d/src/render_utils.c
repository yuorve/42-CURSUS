/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:06:24 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/12 18:20:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_color(t_data *data, int flag)
{
	int	west;
	int	east;
	int	north;
	int	south;

	west = ft_get_rgba(181, 181, 181, 255);
	east = ft_get_rgba(181, 181, 181, 255);
	north = ft_get_rgba(245, 245, 245, 255);
	south = ft_get_rgba(245, 245, 245, 255);
	data->ray->angle = ft_normalized(data->ray->angle);
	if (flag == 0)
	{
		if (data->ray->angle > M_PI / 2 && data->ray->angle < 3 * (M_PI / 2))
			return (west);
		else
			return (east);
	}
	else
	{
		if (data->ray->angle > 0 && data->ray->angle < M_PI)
			return (south);
		else
			return (north);
	}
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

int	ft_load_pixel(mlx_image_t *wall, int pixel)
{
	return (wall->pixels[pixel]);
}
