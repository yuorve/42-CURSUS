/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:21 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/05 20:47:46 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// void	ft_cast_TMP(t_data *data, int x, int y, float angle, int col)
// {
// 	t_point	start;
// 	t_point	end;
// 	int		adjacent;
// 	int		hypotenuse;
// 	int		opposite;
// 	int		down;
// 	int		left;	
// 	int		collision_h;
// 	int		wallhitx;
// 	int		wallhity;
// 	t_point	tile;

// 	(void)col;
// 	down = 0;
// 	left = 0;
// 	if (angle < 0.0001)
// 		angle = M_PI * 2;
// 	if (angle < M_PI)
// 		down = 1;
// 	if (angle > M_PI_2 && angle < 3 * M_PI_2)
// 		left = 1;
// 	wallhitx = floor(x / data->tile_width) * data->tile_width;

	
// 	collision_h = 0;
// 	tile = ft_get_tile(data, data->player_x, data->player_y);
// 	printf("x:%d y:%d\n", tile.x, tile.y);
// 	wallhitx = data->tile_width - data->player_x;
// 	wallhity = data->tile_height - data->player_y;
// 	start.x = data->player_x;
// 	start.y = data->player_y;
// 	while (!collision_h)
// 	{
// 		adjacent = cos(angle) / sin(angle);
// 		end.x = start.x + cos(angle) * adjacent;
// 		end.y = start.y + sin(angle) * adjacent;
// 		tile = ft_get_tile(data, end.x, end.y);
// 		if (ft_collision(data, tile.x, tile.y))
// 			collision_h = 1;
// 		else
// 		{
// 			wallhitx += data->tile_height;
// 			wallhity += data->tile_width;
// 		}
// 	}
// 	ft_draw_line_red(start, end, data->player);
// }

void	ft_cast(t_data *data, int x, int y, float angle, int col)
{
	t_point start;
	t_point end;
	int	interception_x;
	int	interception_y;
	/*float adjacent;
	int	down;
	int left;
	int step_y;
	int step_x;
	int next_yh;
	int next_xh;*/
	int collision_h;
	int box_x;
	int box_y;
	//int	wallhitxh;
	//int wallhityh;

	(void)col;
	interception_x = 0;
	interception_y = 0;
	//down = 0;
	//left = 0;
	if (angle < 0.0001)
		angle = M_PI * 2;
	/*if (angle < M_PI)
		down = 1;
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		left = 1;
	interception_y = floor(y / data->tile_height) * data->tile_height;
	if (down)
		interception_y += data->tile_height;
	adjacent = (interception_y - y) / tan(angle);
	interception_x = x + adjacent;
	step_y = data->tile_height;
	step_x = floor(step_y / tan(angle));
	if (!down)
		step_y = -step_y;
	if ((left && step_x > 0) || (!left && step_x < 0))
		step_x = -step_x;
	next_xh = interception_x;
	next_yh = interception_y;
	if (!down)
		next_yh--;
	collision_h = 0;
	while (!collision_h)
	{
		box_x = round(next_xh / data->tile_width);
		box_y = round(next_yh / data->tile_height);
		if (ft_collision(data, box_x, box_y))
		{
			collision_h = 1;
			wallhitxh = next_xh;
			wallhityh = next_yh;
		}
		else
		{
			next_xh = step_x;
			next_yh = step_y;
		}
	}*/
	start.x = x;
	start.y = y;
	//end.y = wallhityh;
	//end.x = wallhitxh;
	interception_x = x;
	interception_y = y;
	collision_h = 0;
	while (!collision_h)
	{
		box_x = round(interception_x / data->tile_width);
		box_y = round(interception_y / data->tile_height);
		if (ft_collision(data, box_x, box_y))
		{
			collision_h = 1;
			end.y = floor(interception_y);
			end.x = floor(interception_x);
		}
		else
		{
			interception_x += cos(angle) * (data->tile_width / 10);
			interception_y += sin(angle) * (data->tile_height / 10);
		}
	}
	printf("x:%d y:%d\n", interception_x, interception_y);
	ft_draw_line_red(start, end, data->player);
	/*if (angle == (float)(M_PI * 2) || angle == (float)M_PI)
		end.y = y;
	if (angle == (float)M_PI_2 || angle == (float)(3 * M_PI_2))
		end.x = x;
	if ((angle < (float)(5 * M_PI_4) && angle > M_PI) || (angle < (float)(M_PI * 2) && angle > (float)(7 * M_PI_4)))
		end.y = y - cos(angle) * (interception_x - x);
	if ((angle > (float)(3 * M_PI_4) && angle < M_PI) || angle < (float)M_PI_4)
		end.y = y + cos(angle) * (x - interception_x);	
	printf("x:%d y:%d\n", interception_x, interception_y);*/
}
