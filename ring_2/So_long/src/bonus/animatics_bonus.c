/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animatics_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:40:19 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/05 21:01:40 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	timer(void *param)
{
	t_data	*data;

	data = param;
	data->timer++;
}

void	load_player_frames(t_data *data)
{
	mlx_texture_t	*img;

	img = mlx_load_png("resources/bonus/player1.png");
	data->iplayerf1 = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/bonus/player2.png");
	data->iplayerf2 = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/bonus/player3.png");
	data->iplayerf3 = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
}

void	drawing_player_frames(t_data *data)
{
	mlx_image_to_window(data->mlx, data->iplayerf3,
		data->player_pos.x * data->isize, data->player_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->iplayerf2,
		data->player_pos.x * data->isize, data->player_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->iplayerf1,
		data->player_pos.x * data->isize, data->player_pos.y * data->isize);
}

void	move_animation(t_data *data, int x, int y)
{
	data->iplayerf1->instances[0].x = x * data->isize;
	data->iplayerf1->instances[0].y = y * data->isize;
	data->iplayerf2->instances[0].x = x * data->isize;
	data->iplayerf2->instances[0].y = y * data->isize;
	data->iplayerf3->instances[0].x = x * data->isize;
	data->iplayerf3->instances[0].y = y * data->isize;
}

void	player_animation(void *param)
{
	t_data	*data;

	data = param;
	if (data->timer < 15)
	{
		data->iplayerf1->instances[0].enabled = false;
		data->enemyf1->instances[0].enabled = false;
	}
	else if (data->timer < 30)
	{
		data->iplayerf2->instances[0].enabled = false;
		data->enemyf2->instances[0].enabled = false;
	}
	else if (data->timer < 45)
	{
		data->iplayerf2->instances[0].enabled = true;
		data->enemyf2->instances[0].enabled = true;
	}
	else if (data->timer < 60)
	{
		data->iplayerf1->instances[0].enabled = true;
		data->enemyf1->instances[0].enabled = true;
	}
	else if (data->timer > 60)
		data->timer = 0;
}
