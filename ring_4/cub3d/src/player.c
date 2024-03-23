/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:15:16 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 14:08:26 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_check_map_params(t_data *data)
{
	int i;
	int j;

	i = 0;
	//ft_player_pos(data);
	while (data->structure->map[i] != NULL)
	{
		j = 0;
		while (data->structure->map[i][j] != '\0')
		{
			if (!ft_strchr("01NSWE \n", data->structure->map[i][j]))
				exit_error("Wrong cherechter in the map\n");
			if (data->structure->map[i][j] == 'N' || data->structure->map[i][j] == 'S'
			|| data->structure->map[i][j] == 'W' || data->structure->map[i][j] == 'E')
			{
				data->map->player.y = i;
				data->map->player.x = j;
				data->map->direction = data->structure->map[i][j];
				ft_check_player_pos(data, i, j);
				if (data->map->player.x == 0 || data->map->player.y == 0)
					exit_error("Player is in wrong position\n");
				//printf("player x = %d\n", data->map->player.x);
				//printf("player y = %d\n", data->map->player.y);
				data->map->n_player++;
			}
			j++;
		}
		i++;
	}
	if (data->map->n_player != 1)
		exit_error("Wrong number of players\n");
	ft_get_player_dir(data);

	// if (data->structure->size_x < 3 || data->structure->size_y < 3)
	// 	exit_error("Map is too small\n");
}

void ft_get_player_dir(t_data *data)
{
	if(data->map->direction == 'N')
	{
		data->player_dir = N;
	}
	else if(data->map->direction == 'S')
	{
		data->player_dir = S;
	}
	else if(data->map->direction == 'E')
	{
		data->player_dir = E;
	}
	else if(data->map->direction == 'W')
	{
		data->player_dir = W;
	}
	//printf("player_dir = %f\n", data->player_dir);
}

void	ft_check_player_pos(t_data *data, int y, int x)
{

	if (data->structure->map[y + 1][x] == ' ' || data->structure->map[y - 1][x] == ' '
	|| data->structure->map[y][x + 1] == ' ' || data->structure->map[y][x - 1] == ' '
	|| data->structure->map[y + 1][x] == '\n' || data->structure->map[y - 1][x] == '\n'
	|| data->structure->map[y][x + 1] == '\n' || data->structure->map[y][x - 1] == '\n')
	{
		exit_error("Player is in wrong position\n");
	}	
	// if (data->map->player.x + 1 == ' ' || data->map->player.x - 1 == ' '
	// || data->map->player.y + 1 == ' ' || data->map->player.y - 1 == ' '
	// || data->map->player.x + 1 == '\0' || data->map->player.x - 1 == '\0'
	// || data->map->player.y + 1 == '\0' || data->map->player.y - 1 == '\0')
	// {
	// 	printf("here\n");
	// 	exit_error("Player is out from the map\n");
		
	// }
	
}

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
	data->ply->pos->x = data->map->player.x * TILE_SIZE + TILE_SIZE / 2;
	data->ply->pos->y = data->map->player.y * TILE_SIZE + TILE_SIZE / 2;
	data->ply->forward = 0;
	data->ply->turn = 0;
	data->ply->angle = M_PI;
	printf("player angle = %f\n", data->ply->angle);
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
