/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:15:16 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/26 18:20:01 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_player(t_data *data, int y, int x)
{
	data->map->player.x = x;
	data->map->player.y = y;
	data->map->direction = data->structure->map[y][x];
	ft_check_player_pos(data, y, x);
	if (data->map->player.x == 0 || data->map->player.y == 0)
		exit_error("Player is in wrong position\n");
}

void	ft_check_map_params(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->structure->map[i] != NULL)
	{
		j = 0;
		while (data->structure->map[i][j] != '\0')
		{
			if (!ft_strchr("01DNSWE \n", data->structure->map[i][j]))
				exit_error("Wrong character in the map\n");
			if (ft_strchr("NSWE", data->structure->map[i][j]))
			{
				ft_get_player(data, i, j);
				data->map->n_player++;
				data->structure->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (data->map->n_player != 1)
		exit_error("Wrong number of players\n");
	ft_get_player_dir(data);
}

void	ft_get_player_dir(t_data *data)
{
	if (data->map->direction == 'N')
	{
		data->player_dir = N;
	}
	else if (data->map->direction == 'S')
	{
		data->player_dir = S;
	}
	else if (data->map->direction == 'E')
	{
		data->player_dir = E;
	}
	else if (data->map->direction == 'W')
	{
		data->player_dir = W;
	}
}

void	ft_check_player_pos(t_data *data, int y, int x)
{
	if (data->structure->map[y + 1][x] == ' '
	|| data->structure->map[y - 1][x] == ' '
	|| data->structure->map[y][x + 1] == ' '
	|| data->structure->map[y][x - 1] == ' '
	|| data->structure->map[y + 1][x] == '\n'
	|| data->structure->map[y - 1][x] == '\n'
	|| data->structure->map[y][x + 1] == '\n'
	|| data->structure->map[y][x - 1] == '\n')
	{
		exit_error("Player is in wrong position\n");
	}
}
