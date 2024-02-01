/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:21 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/01 19:58:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cast(t_data *data, int col)
{
	t_point	start;
	t_point	end;
	int		down;
	int		left;	
	int		collision_h;
	int		wallhitx;
	int		wallhity;
	t_point	tile;

	(void)col;
	down = 0;
	left = 0;
	if (data->anglerotation < M_PI)
		down = 1;
	if (data->anglerotation > M_PI_2 && data->anglerotation < 3 * M_PI_2)
		left = 1;
	collision_h = 0;
	tile = ft_get_tile(data, data->player_x, data->player_y);
	printf("x:%d y:%d\n", tile.x, tile.y);
	wallhitx = data->tile_width;
	wallhity = data->tile_height;
	start.x = data->player_x;
	start.y = data->player_y;
	while (!collision_h)
	{
		end.x = start.x + cos(data->anglerotation) * wallhitx;
		end.y = start.y + sin(data->anglerotation) * wallhity;
		tile = ft_get_tile(data, end.x, end.y);
		if (ft_collision(data, tile.x, tile.y))
			collision_h = 1;
		else
		{
			wallhitx += data->tile_height;
			wallhity += data->tile_width;
		}
	}
	ft_draw_line_red(start, end, data->player);
}

void	ft_cast_OLD(t_data *data, int x, int y, float angle, int col)
{
	t_point start;
	t_point end;
	int	interception_x;
	int	interception_y;
	int	down;
	int left;
	int collision_h;
	int adjacent;
	int step_y;
	int step_x;
	int next_y;
	int next_x;
	int box_x;
	int box_y;
	int	wallhitx;
	int wallhity;
	int wallhitxh;
	int wallhityh;
	int wallhitxv;
	int wallhityv;

	(void)col;
	(void)interception_x;
	(void)wallhitxv;
	(void)wallhityv;
	wallhitx = 0;
	wallhity = 0;
	wallhitxh = 0;
	wallhityh = 0;
	wallhitxv = 0;
	wallhityv = 0;
	interception_x = 0;
	interception_y = 0;
	down = 0;
	left = 0;
	if (angle < M_PI)
		down = 1;
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		left = 1;
	collision_h = 0;
	interception_y = floor(y / data->tile_height) * data->tile_height;
	if (down)
		interception_y += data->tile_height;
	adjacent = (interception_y - y) / tan(angle);
	interception_x = x + adjacent;
	step_y = data->tile_height;
	step_x = round(step_y / tan(angle));
	if (!down)
		step_y = -step_y;
	if ((left && step_x > 0) || (!left && step_x < 0))
		step_x = -step_x;
	next_y = step_y;
	next_x = step_x;
	if (!down)
		next_y--;
	while (!collision_h)
	{
		box_x = floor(next_x / data->tile_width);
		box_y = floor(next_y / data->tile_height);
		if (ft_collision(data, box_x, box_y))
		{
			collision_h = 1;
			wallhitxh = next_x;
			wallhityh = next_y;
		}
		else
		{
			next_x = step_x;
			next_y = step_y;
		}
	}
	//(void)wallhitxh;
	//(void)wallhityh;
	start.x = x;
	start.y = y;
	end.x = wallhitxh;
	end.y = wallhityh;
	printf("x:%d y:%d\n", wallhitxh, wallhityh);
	ft_draw_line_red(start, end, data->player);
}
