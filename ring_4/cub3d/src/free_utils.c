/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 19:27:32 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/25 18:03:52 by yoropeza         ###   ########.fr       */
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

void	ft_free(t_data *data)
{
	ft_free_structure(data->structure);
	free(data->structure);
	free(data->map);
	free(data->map_path);
	free(data->ply->pos);
	free(data->ply);
	free(data->ray);
	ft_free_texture(data);
	free(data);
}
