/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:47:26 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/27 19:19:39 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_keys_press(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_player_move(data, "UP");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_player_move(data, "DOWN");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_player_move(data, "LEFT");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_player_move(data, "RIGHT");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_player_move(data, "TURN LEFT");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_player_move(data, "TURN RIGHT");
}

void	ft_keys_release(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP FORWARD");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP FORWARD");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP SIDLE");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP SIDLE");
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP TURN");
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE)
		ft_player_move(data, "STOP TURN");
}
