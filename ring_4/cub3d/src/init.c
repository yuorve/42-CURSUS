/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:56:28 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/04 19:56:29 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map_init(t_map *map) 
{
    map->n_rows = 0;
    map->n_lines = 0;
    map->n_player = 0;
    map->direction = 0;
    map->player.x = 0;
    map->player.y = 0;
}


void	ft_structure_init(t_structure *structure) 
{
	structure->NO = NULL;
	structure->SO = NULL;
	structure->WE = NULL;
	structure->EA = NULL;
	structure->F = 0;
	structure->C = 0;
    structure->count_params = 0;
    structure->cntl_map = 0;
    structure->map = NULL;
    structure->copy_map = NULL;
    structure->size_x = 0;
    structure->size_y = 0;
    structure->full_size = 0;
}
