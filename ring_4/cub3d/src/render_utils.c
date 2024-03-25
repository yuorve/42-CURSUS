/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:06:24 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/23 17:54:52 by angalsty         ###   ########.fr       */
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

mlx_image_t	*ft_load_image(t_data *data, int x, int y)
{
	mlx_image_t		*wall;
	mlx_texture_t	*texture;
	uint32_t		*xy;
	uint32_t		*wh;

	texture = mlx_load_png("assets/walls.png");
	xy = calloc(2, sizeof(uint32_t));
	wh = calloc(2, sizeof(uint32_t));
	xy[0] = (TEXTURE * x);
	xy[1] = (TEXTURE * y);
	wh[0] = TEXTURE;
	wh[1] = TEXTURE;
	wall = mlx_texture_area_to_image(data->mlx, texture, xy, wh);
	mlx_delete_texture(texture);
	free(xy);
	free(wh);
	return (wall);
}

int	ft_load_pixel(mlx_image_t *wall, int pixel)
{
	return (wall->pixels[pixel]);
}
