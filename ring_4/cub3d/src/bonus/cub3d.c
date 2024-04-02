/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:36 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/26 18:10:50 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move(mlx_t *mlx, t_data *data)
{
	t_point	new;
	float	angle;
	float	side_angle;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	angle = data->ply->angle;
	side_angle = ft_normalized(angle - (M_PI_2));
	if (data->ply->sidle == 0)
		new = ft_get_pos(data->ply->pos, angle, data->ply->forward);
	else
		new = ft_get_pos(data->ply->pos, side_angle, data->ply->sidle);
	if (data->ply->mouse_turn != 0)
		data->ply->angle += (data->ply->mouse_turn * R_SPEED);
	else
		data->ply->angle += (data->ply->turn * R_SPEED);
	data->ply->angle = ft_normalized(data->ply->angle);
	if (!ft_player_collision(data, new.x, new.y))
	{
		data->ply->pos->x = new.x;
		data->ply->pos->y = new.y;
	}
}

void	ft_keys_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	ft_keys_press(keydata, param);
	ft_keys_release(keydata, param);
}

void	ft_mouse_hook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = param;
	(void)ydelta;
	data->ply->mouse_turn = 0;
	if (xdelta < (S_W / 2) + 10)
		data->ply->mouse_turn = -1;
	else if (xdelta > (S_W / 2) + 10)
		data->ply->mouse_turn = 1;
	else
		data->ply->mouse_turn = 0;
	mlx_set_mouse_pos(data->mlx, S_W / 2, S_H / 2);
}

void	ft_game(void *param)
{
	t_data	*data;

	data = param;
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, S_W, S_H);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	ft_move(data->mlx, data);
	ft_cast_rays(data);
	data->ply->mouse_turn = 0;
}
