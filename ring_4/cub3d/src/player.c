/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:25:08 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/31 21:24:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_player_init(t_data *data)
{
	data->forward = 0;
	data->turn = 0;
	data->anglerotation = 0;
	data->speed_move = 3;
	data->speed_turn = 3 * (M_PI / 180);
}

void	ft_player(t_data *data)
{
	mlx_t	*mlx;
	t_point	start;
	t_point	end;

	mlx = data->mlx;
	data->player = mlx_new_image(mlx, data->map_width, data->map_height);
	mlx_image_to_window(mlx, data->player, 0, 0);
	start.x = data->player_x - 3;
	start.y = data->player_y - 3;
	end.x = 6;
	end.y = 6;
	ft_draw_square(start, end, data->player);
	start.x = data->player_x;
	start.y = data->player_y;
	end.x = start.x + cos(data->anglerotation) * 20;
	end.y = start.y + sin(data->anglerotation) * 20;
	ft_draw_line(start, end, data->player);
}

void	ft_player_move(t_data *data, char *direction)
{
	if (ft_strncmp(direction, "UP", 2) == 0)
		data->forward = 1;
	else if (ft_strncmp(direction, "DOWN", 4) == 0)
		data->forward = -1;
	else if (ft_strncmp(direction, "LEFT", 4) == 0)
		data->sidle = 1;
	else if (ft_strncmp(direction, "RIGHT", 5) == 0)
		data->sidle = -1;
	else if (ft_strncmp(direction, "TURN LEFT", 9) == 0)
		data->turn = -1;
	else if (ft_strncmp(direction, "TURN RIGHT", 10) == 0)
		data->turn = 1;
	else if (ft_strncmp(direction, "STOP SIDLE", 10) == 0)
		data->sidle = 0;
	else if (ft_strncmp(direction, "STOP TURN", 9) == 0)
		data->turn = 0;
	else if (ft_strncmp(direction, "STOP FORWARD", 12) == 0)
		data->forward = 0;
}

int	ft_player_collision(t_data *data, int x, int y)
{
	int	res;
	int	box_x;
	int	box_y;

	res = 0;
	box_x = (x + (data->tile_width / 2)) / data->tile_width;
	box_y = (y + (data->tile_height / 2)) / data->tile_height;
	if (ft_collision(data, box_x, box_y))
		res = 1;
	return (res);
}
