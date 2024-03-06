/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:08 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/01 18:43:20 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_player_init(t_data *data)
{
	data->ply->pos->x = 3 * TILE_SIZE + TILE_SIZE / 2;
	data->ply->pos->y = 3 * TILE_SIZE + TILE_SIZE / 2;
	data->ply->forward = 0;
	data->ply->turn = 0;
	data->ply->angle = M_PI;
}

void	ft_player(t_data *data)
{
	mlx_t	*mlx;
	t_point	start;
	t_point	end;

	mlx = data->mlx;
	data->ply->img = mlx_new_image(mlx, S_W, S_H);
	mlx_image_to_window(mlx, data->ply->img, 0, 0);
	start.x = data->ply->pos->x - 3;
	start.y = data->ply->pos->y - 3;
	end.x = 6;
	end.y = 6;
	ft_draw_square(start, end, data->ply->img);
	start.x = data->ply->pos->x;
	start.y = data->ply->pos->y;
	end.x = start.x + cos(data->ply->angle) * 20;
	end.y = start.y + sin(data->ply->angle) * 20;
	ft_draw_line(start, end, data->ply->img);
}

void	ft_player_move(t_data *data, char *direction)
{
	if (ft_strncmp(direction, "UP", 2) == 0)
		data->ply->forward = 1;
	else if (ft_strncmp(direction, "DOWN", 4) == 0)
		data->ply->forward = -1;
	else if (ft_strncmp(direction, "LEFT", 4) == 0)
		data->ply->sidle = 1;
	else if (ft_strncmp(direction, "RIGHT", 5) == 0)
		data->ply->sidle = -1;
	else if (ft_strncmp(direction, "TURN LEFT", 9) == 0)
		data->ply->turn = -1;
	else if (ft_strncmp(direction, "TURN RIGHT", 10) == 0)
		data->ply->turn = 1;
	else if (ft_strncmp(direction, "STOP SIDLE", 10) == 0)
		data->ply->sidle = 0;
	else if (ft_strncmp(direction, "STOP TURN", 9) == 0)
		data->ply->turn = 0;
	else if (ft_strncmp(direction, "STOP FORWARD", 12) == 0)
		data->ply->forward = 0;
}

int	ft_player_collision(t_data *data, int x, int y)
{
	int	res;
	int	box_x;
	int	box_y;

	res = 0;
	box_x = round(x / TILE_SIZE);
	box_y = round(y / TILE_SIZE);
	if (ft_collision(data, box_x, box_y))
		res = 1;
	return (res);
}
