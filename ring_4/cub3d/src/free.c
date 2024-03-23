/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:56:24 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 16:29:18 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(const char *message)
{
	printf("Error\n%s", message);
	exit(EXIT_FAILURE);
}

void	ft_free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
	}
	free(str);
	str = NULL;
}

void	ft_free_struct(t_data *data)
{
	free(data->structure);
	free(data->map);
}

void	ft_free_structure(t_structure *structure)
{
	if (structure->NO != NULL)
		free(structure->NO);
	if (structure->SO != NULL)
		free(structure->SO);
	if (structure->WE != NULL)
		free(structure->WE);
	if (structure->EA != NULL)
		free(structure->EA);
	if (structure->map != NULL)
		ft_free_matrix(structure->map);
	if (structure->copy_map != NULL)
		ft_free_matrix(structure->copy_map);
}

// void	ft_free_map(t_structure *map) 
// {
// 	int i;

// 	i = 0;
//     while (i < map->n_rows) 
// 	{
//         free(map->map[i]);
// 		i++;
//     }
//     free(map->map);
// }
