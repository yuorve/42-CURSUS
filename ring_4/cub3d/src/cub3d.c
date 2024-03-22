/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:36 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/20 19:30:45 by yoropeza         ###   ########.fr       */
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
	data->ply->angle += (data->ply->turn * R_SPEED);
	data->ply->angle = ft_normalized(data->ply->angle);
	if (!ft_player_collision(data, new.x, new.y))
	{
		data->ply->pos->x = new.x;
		data->ply->pos->y = new.y;
	}
	//mlx_delete_image(data->mlx, data->ply->img);
	//ft_player(data);
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

void	ft_void(void)
{
	system("leaks -q 'cub3d'");
}

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	atexit(ft_void);
	if (argc == 2)
	{
		data = calloc(1, sizeof(t_data));
		data->wall = calloc(1, sizeof(t_wall));
		data->ply = calloc(1, sizeof(t_player));
		data->ply->pos = calloc(1, sizeof(t_point));
		data->ray = calloc(1, sizeof(t_ray));
		data->map = calloc(1, sizeof(t_map));
		data->map->file = ft_strjoin("assets/maps/", argv[1]);
		read_map(data);
		data->mlx = mlx_init(S_W, S_H, "Cube 3D - Play it!", true);
		ft_load_texture(data);
		//ft_draw_scene(data);
		ft_player_init(data);
		//ft_player(data);
		mlx_key_hook(data->mlx, &ft_keys_hook, data);
		mlx_loop_hook(data->mlx, &ft_game, data);
		mlx_loop_hook(data->mlx, &ft_minimap, data);
		mlx_loop(data->mlx);
		mlx_terminate(data->mlx);
		ft_free(data);
	}
	return (EXIT_SUCCESS);
}
