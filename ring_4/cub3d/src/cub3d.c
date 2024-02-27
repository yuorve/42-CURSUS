/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:36 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/20 19:16:48 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move(mlx_t *mlx, t_data *data)
{
	t_point	new;
	float	angle;
	float	side_angle;
	int		speed;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	angle = data->ply->angle;
	speed = P_SPEED;
	side_angle = ft_normalized(angle - (M_PI_2));
	if (data->ply->sidle == 0)
	{
		new.x = data->ply->pos->x + round(data->ply->forward * cos(angle) * speed);
		new.y = data->ply->pos->y + round(data->ply->forward * sin(angle) * speed);
	}
	else
	{
		new.x = data->ply->pos->x + round(data->ply->sidle * cos(side_angle) * speed);
		new.y = data->ply->pos->y + round(data->ply->sidle * sin(side_angle) * speed);
	}
	data->ply->angle += (data->ply->turn * R_SPEED);
	data->ply->angle = ft_normalized(data->ply->angle);
	if (!ft_player_collision(data, new.x, new.y))
	{
		data->ply->pos->x = new.x;
		data->ply->pos->y = new.y;
	}
	mlx_delete_image(data->mlx, data->ply->img);
	ft_player(data);
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

void	ft_game(void *param)
{
	t_data	*data;

	data = param;
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, S_W, S_H);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	ft_move(data->mlx, data);
	ft_cast_rays(data);
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		//ft_bzero(data, sizeof(t_data));
		data = calloc(1, sizeof(t_data));
		data->ply = calloc(1, sizeof(t_player));
		data->ply->pos = calloc(1, sizeof(t_point));
		data->ray = calloc(1, sizeof(t_ray));
		data->map = calloc(1, sizeof(t_map));
		data->map->file = ft_strjoin("assets/maps/", argv[1]);
		read_map(data);		
		data->mlx = mlx_init(S_W, S_H, "Cube 3D - Play it!", true);
		ft_draw_scene(data);
		ft_player_init(data);		
		ft_player(data);
		mlx_key_hook(data->mlx, &ft_keys_hook, data);
		mlx_loop_hook(data->mlx, &ft_game, data);
		mlx_loop(data->mlx);
		mlx_terminate(data->mlx);
		free(data->map->file);
	}
	return (EXIT_SUCCESS);
}
