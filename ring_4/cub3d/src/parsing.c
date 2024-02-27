/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:38:00 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/27 21:00:32 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	read_map(t_data *data)
{
	int		fd;
	int		i;

	fd = open(data->map->file, O_RDONLY);
	if (fd < 0)
		exit(printf("Error Opening file\n"));
	i = 0;
	data->map->width = 22;
	data->map->height = 10;
	data->map->matrix = ft_calloc(data->map->height, data->map->width);
	data->map->matrix[i] = get_next_line(fd);
	while (data->map->matrix[i++] != NULL)
		data->map->matrix[i] = get_next_line(fd);
	close(fd);
}
