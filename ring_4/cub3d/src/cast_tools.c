/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:21 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/31 21:23:31 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_cast(t_data *data, int x, int y, float angle, int col)
{
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

	(void)col;
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
	step_x = step_y / tan(angle);
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
		box_x = step_x / data->tile_width;
		box_y = step_y / data->tile_height;
		if (ft_collision(data, box_x, box_y))
			collision_h = 1;
	}
}
