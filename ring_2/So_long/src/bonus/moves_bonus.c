/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:37:36 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/06 20:23:30 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	exiting(t_data *data)
{
	if (data->player_pos.y == data->exit_pos.y
		&& data->player_pos.x == data->exit_pos.x)
	{
		if (data->points == data->keys)
		{
			mlx_terminate(data->mlx);
			ft_freeplus(data->map, data->map_height);			
			ft_printf("\e[32m You Win! - GAME OVER\e[0m\n");
			exit(0);
		}
	}
}

void	keys(t_data *data)
{
	int	i;
	int	size;

	size = data->isize;
	if (data->map[data->player_pos.y][data->player_pos.x] == 'C')
	{
		data->points++;
		ft_printf("Points: %d\n", data->points);
		i = 0;
		while (i < data->keys)
		{
			if (data->ikeys->instances[i].x == data->player_pos.x * size
				&& data->ikeys->instances[i].y == data->player_pos.y * size)
			{
				data->ikeys->instances[i].x = (data->points * data->isize) + 64;
				data->ikeys->instances[i].y = data->map_height * data->isize;
			}
			i++;
		}
		if (data->points == data->keys)
			data->exit_close->instances[0].enabled = false;
	}
}

void	moves(t_data *data, int x, int y)
{
	if (data->map[data->player_pos.y + y][data->player_pos.x + x] != '1')
	{
		data->steps++;
		data->map[data->player_pos.y][data->player_pos.x] = '0';
		data->player_pos.y = data->player_pos.y + y;
		data->player_pos.x = data->player_pos.x + x;
		data->iplayer->instances[0].x = data->player_pos.x * data->isize;
		data->iplayer->instances[0].y = data->player_pos.y * data->isize;
		move_animation(data, data->player_pos.x, data->player_pos.y);		
		ft_printf("Steps: %d\n", data->steps);
		keys(data);
		exiting(data);
		print_score(data);
	}
}
