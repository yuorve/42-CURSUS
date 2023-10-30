/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:43:37 by yoropeza          #+#    #+#             */
/*   Updated: 2023/10/30 13:10:06 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_checks(t_data *data, char *map)
{
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	while (data->map[j][i] != NULL)
	{
		if (data->map[j][i++] != '1')
			quit(data, "Error file structure");
	}
	while (data->map[data->map_height - 1][--i] != NULL)
	{
		if (data->map[data->map_height - 1][i] != '1')
			quit(data, "Error file structure");
	}	
	while (data->map[j] != NULL)
	{		
		if (data->map_width != ft_strlen(data->map[j]) - 1)
			quit(data, "Error file structure");
		if (data->map[j][0] != '1' && data->map[j][data->map_width - 1] != '1')
			quit(data, "Error file structure");
		j++;
	}
}

void	map_sizes(t_data *data, char *map)
{
	int		fd;
	char	*str;

	fd = open(ft_strjoin("assets/", map), O_RDONLY);
	if (fd < 0)
		quit(data, "Error opening file");
	str = get_next_line(fd);
	data->map_width = ft_strlen(str) - 1;
	while (str != NULL)
	{
		if (data->map_width != ft_strlen(str) - 1)
			quit(data, "Error file structure");
		data->map_height++;		
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
}

void	reading(t_data *data, char *map)
{
	int		fd;
	int		i;
	
	if (ft_strncmp(ft_strrchr(map, '.'), ".ber", 4))
		quit(data, "Error file name");
	fd = open(ft_strjoin("assets/", map), O_RDONLY);
	if (fd < 0)
		quit(data, "Error opening file");
	i = 0;
	map_sizes(data, map);	
	data->map = ft_calloc(data->map_height, data->map_width);
	data->map[i] = get_next_line(fd);
	while (data->map[i++] != NULL)
	{
		data->map[i] = get_next_line(fd);
	}
	close(fd);
	map_checks(data, map);
}
