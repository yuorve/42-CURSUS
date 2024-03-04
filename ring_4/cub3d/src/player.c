/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:15:16 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/04 21:16:23 by angalsty         ###   ########.fr       */
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

