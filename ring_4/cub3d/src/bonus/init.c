/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:56:28 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/25 17:46:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init(t_data *data)
{
	ft_map_init(data->map);
	ft_structure_init(data->structure);
}

void	ft_map_init(t_map *map)
{
	map->n_player = 0;
	map->direction = 0;
	map->player.x = 0;
	map->player.y = 0;
}

void	ft_structure_init(t_structure *structure)
{
	structure->no = NULL;
	structure->so = NULL;
	structure->we = NULL;
	structure->ea = NULL;
	structure->f = 0;
	structure->c = 0;
	structure->count_params = 0;
	structure->cntl_map = 0;
	structure->map = NULL;
	structure->copy_map = NULL;
	structure->size_x = 0;
	structure->size_y = 0;
	structure->full_size = 0;
}
