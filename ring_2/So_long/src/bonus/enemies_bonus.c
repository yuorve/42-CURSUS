/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:16:18 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/05 21:24:58 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	enemies(void *param)
{
	t_data	*data;
	int		x;
	int		y;

	data = param;
	x = 0;
	y = 0;
	if (data->timer % 2 == 0)
		x = -1;
	if (data->timer % 3 == 0)
		y = -1;
	if (data->timer % 4 == 0)
		x = 1;
	if (data->timer % 5 == 0)
		y = 1;
	x = data->enemy_pos.x + x;
	y = data->enemy_pos.y + y;
	if (data->player_pos.y == y && data->player_pos.x == x)
	{
		mlx_terminate(data->mlx);
		ft_freeplus(data->map, data->map_height);
		exit(0);
	}
	if (data->map[data->enemy_pos.y + y][data->enemy_pos.x + x] != '1')
		move_enemy(data, x, y);
}

void	load_enemy_frames(t_data *data)
{
	mlx_texture_t	*img;

	img = mlx_load_png("resources/bonus/monster1.png");
	data->enemyf1 = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/bonus/monster2.png");
	data->enemyf2 = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
	img = mlx_load_png("resources/bonus/monster3.png");
	data->enemyf3 = mlx_texture_to_image(data->mlx, img);
	mlx_delete_texture(img);
}

void	drawing_enemy_frames(t_data *data)
{
	mlx_image_to_window(data->mlx, data->ground,
		data->enemy_pos.x * data->isize, data->enemy_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->enemyf3,
		data->enemy_pos.x * data->isize, data->enemy_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->enemyf2,
		data->enemy_pos.x * data->isize, data->enemy_pos.y * data->isize);
	mlx_image_to_window(data->mlx, data->enemyf1,
		data->enemy_pos.x * data->isize, data->enemy_pos.y * data->isize);
}

void	move_enemy(t_data *data, int x, int y)
{
	data->enemyf1->instances[0].x = x * data->isize;
	data->enemyf1->instances[0].y = y * data->isize;
	data->enemyf2->instances[0].x = x * data->isize;
	data->enemyf2->instances[0].y = y * data->isize;
	data->enemyf3->instances[0].x = x * data->isize;
	data->enemyf3->instances[0].y = y * data->isize;
}

void	enemy_animation(void *param)
{
	t_data	*data;

	data = param;
	if (data->timer < 15)
		data->enemyf1->instances[0].enabled = false;
	else if (data->timer < 30)
		data->enemyf2->instances[0].enabled = false;
	else if (data->timer < 45)
		data->enemyf2->instances[0].enabled = true;
	else if (data->timer < 60)
		data->enemyf1->instances[0].enabled = true;
	else if (data->timer > 60)
		data->timer = 0;
}
