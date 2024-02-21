/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:21 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/21 20:03:32 by yoropeza         ###   ########.fr       */
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
	float	interception_x;
	float	interception_y;
	int	down;
	int left;
	float adjacent;
	float step_y;
	float step_x;
	/*int next_yh;
	int next_xh;*/
	int collision_h;
	int box_x;
	int box_y;
	//int	wallhitxh;
	//int wallhityh;

	(void)col;
	interception_x = 0;
	interception_y = 0;
	down = 0;
	left = 0;
	if (angle < 0.0001)
		angle = M_PI * 2;
	if (angle < M_PI)
		down = 1;
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
		left = 1;
	interception_y = floor(y / data->tile_height) * data->tile_height;
	if (down)
		interception_y += data->tile_height;
	if (y > interception_y)
		adjacent = (y - interception_y) / tan(angle);
	else
		adjacent = (interception_y - y) / tan(angle);
	interception_x = x + adjacent;
	step_y = data->tile_height;
	step_x = step_y / tan(angle);
	if (!down)
		step_y = -step_y;
	if ((left && step_x > 0) || (!left && step_x < 0))
		step_x = -step_x;
	if (!down)
		interception_y--;
	start.x = x;
	start.y = y;
	// CORREGIR INICIO *******
	interception_x = x;
	interception_y = y;
	// ***********************
	collision_h = 0;
	while (!collision_h)
	{
		box_x = floor(interception_x / data->tile_width);
		box_y = floor(interception_y / data->tile_height);
		if (ft_collision(data, box_x, box_y))
		{
			collision_h = 1;
			end.y = interception_y;
			end.x = interception_x;
		}
		else
		{
			interception_y += sin(angle);
			interception_x += cos(angle);
		}
	}
	printf("BOX x:%d y:%d\n", box_x, box_y);
	printf("END x:%d y:%d\n", end.x, end.y);
	printf("STEP x:%f y:%f angle:%f\n", step_x, step_y, angle);
	printf("INTER x:%f y:%f angle:%f\n", interception_x, interception_y, angle);
	ft_draw_line_red(start, end, data->player);
}
