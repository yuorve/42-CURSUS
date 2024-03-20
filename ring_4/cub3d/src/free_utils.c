/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:27:32 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/20 19:28:00 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_free_texture(t_data *data)
{
	mlx_delete_texture(data->wall->north);
	mlx_delete_texture(data->wall->south);
	mlx_delete_texture(data->wall->east);
	mlx_delete_texture(data->wall->west);
	free(data->wall);
}

void	ft_free_matrix(char **array)
{
	int	i;

	if (array)
	{
		i = 0;
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
		array = NULL;
	}
}

void	ft_free(t_data *data)
{
	free(data->map->file);
	free(data->ply->pos);
	free(data->ply);
	free(data->ray);
	free(data);
	ft_free_texture(data);
	ft_free_matrix(data->map->matrix);
	free(data->map);
}
