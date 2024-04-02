/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:29:45 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/25 17:37:19 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_draw_player(t_data *data)
{
	t_point	start;
	t_point	end;

	start.x = (data->ply->pos->x / TILE_SIZE) * (TILE_SIZE / 5) + 5;
	start.y = (data->ply->pos->y / TILE_SIZE) * (TILE_SIZE / 5) + 5;
	end.x = 6;
	end.y = 6;
	ft_squar(start, end, data->img, 0xFF0000FF);
	start.x = (data->ply->pos->x / TILE_SIZE) * (TILE_SIZE / 5) + 8;
	start.y = (data->ply->pos->y / TILE_SIZE) * (TILE_SIZE / 5) + 8;
	end.x = start.x + cos(data->ply->angle) * 10;
	end.y = start.y + sin(data->ply->angle) * 10;
	ft_draw_line_red(start, end, data->img);
}

void	ft_draw_walls(t_data *data)
{
	t_point	start;
	t_point	end;
	int		i;
	int		j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (data->map->matrix[i][j] == '1')
			{
				start.x = j * (TILE_SIZE / 5) + 5;
				start.y = i * (TILE_SIZE / 5) + 5;
				end.x = TILE_SIZE / 5;
				end.y = TILE_SIZE / 5;
				ft_squar(start, end, data->img, 0x000000FF);
			}
		}
	}
}

void	ft_draw_ground(t_data *data)
{
	t_point		start;
	t_point		end;

	start.x = 5;
	start.y = 5;
	end.x = data->map->width * (TILE_SIZE / 5);
	end.y = data->map->height * (TILE_SIZE / 5);
	ft_squar(start, end, data->img, 0xFFFFFFFF);
}

void	ft_minimap(void *param)
{
	t_data	*data;

	data = param;
	ft_draw_ground(data);
	ft_draw_walls(data);
	ft_draw_player(data);
}
