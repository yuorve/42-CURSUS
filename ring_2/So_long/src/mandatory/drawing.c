/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:16:04 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/05 20:47:42 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	load_images(t_data *data)
{
	mlx_texture_t	*img;

	img = mlx_load_png("resources/wall.png");
	data->wall = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/ground.png");
	data->ground = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/key.png");
	data->ikeys = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/player.png");
	data->iplayer = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/exit_close.png");
	data->exit_close = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/exit_open.png");
	data->exit_open = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
}

void	mapping(t_data *data)
{
	int	i;
	int	j;
	int	size;

	size = data->isize;
	i = -1;
	while (++i < (int)data->map_height)
	{
		j = -1;
		while (++j < (int)data->map_width)
		{
			if (data->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->wall, j * size, i * size);
			if (data->map[i][j] == '0')
				mlx_image_to_window(data->mlx, data->ground,
					j * size, i * size);
			if (data->map[i][j] == 'C')
			{
				mlx_image_to_window(data->mlx, data->ground,
					j * size, i * size);
				mlx_image_to_window(data->mlx, data->ikeys,
					j * size, i * size);
			}
		}
	}
}

void	draw_player(t_data *data)
{
	mlx_image_to_window(data->mlx, data->ground,
		data->exit_pos.x * data->isize, data->exit_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->exit_open,
		data->exit_pos.x * data->isize, data->exit_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->exit_close,
		data->exit_pos.x * data->isize, data->exit_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->ground,
		data->player_pos.x * data->isize, data->player_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->iplayer,
		data->player_pos.x * data->isize, data->player_pos.y * data->isize);
}

void	drawing(t_data *data)
{
	data->mlx = mlx_init(data->map_width * data->isize,
			data->map_height * data->isize, "So long - Enjoy it!", true);
	load_images(data);
	mapping(data);
	draw_player(data);
}
