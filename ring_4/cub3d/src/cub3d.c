/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:36 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/31 18:24:36 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move(mlx_t *mlx, t_data *data)
{
    t_point new;
	float	angle;
	int		speed;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	angle = data->anglerotation;
	speed = data->speed_move;
	new.x = data->player_x + (data->forward * cos(angle) * speed);
	new.y = data->player_y + (data->forward * sin(angle) * speed);
	data->anglerotation += (data->turn * data->speed_turn);
	data->anglerotation = ft_normalized(data->anglerotation);
	if (!ft_player_collision(data, new.x, new.y))
	{
		data->player_x = new.x;
		data->player_y = new.y;
	}	
	mlx_delete_image(data->mlx, data->player);
	ft_player(data);
}

void	ft_keys_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_player_move(data, "UP");
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_player_move(data, "DOWN");
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_player_move(data, "LEFT");
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_player_move(data, "RIGHT");
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP FORWARD");
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP FORWARD");
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP TURN");
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP TURN");
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
}


void	ft_game(void *param)
{
	t_data	*data;

	data = param;
	ft_move(data->mlx, data);	
}

int32_t	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{		
		ft_bzero(&data, sizeof(t_data));
		data.mapfile = ft_strjoin("assets/maps/", argv[1]);
		read_map(&data);
		data.mlx = mlx_init(800, 600, "Cube 3D - Play it!", true);
		ft_draw_scene(&data);
		ft_player_init(&data);
		data.player_x = 100;
		data.player_y = 100;		
		ft_player(&data);
		mlx_key_hook(data.mlx, &ft_keys_hook, &data);
		mlx_loop_hook(data.mlx, &ft_game, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
		free(data.mapfile);
	}
	return (EXIT_SUCCESS);
}
