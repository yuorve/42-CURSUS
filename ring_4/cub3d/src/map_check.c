/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:59:55 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/12 18:42:09 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_map_param(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if((line[i] == '1' || line[i] == '0') && ft_is_param(line) == 0)
			return (1);
		i++;
	}
	return(0);
}

void ft_check_map(t_data *data)
{
	int i;
	char *line;

	i = 0;
	data->map_fd = open(data->map_path, O_RDONLY);
	data->structure->map = (char **)malloc(sizeof(char *) * (data->structure->size_y + 1));
	if (!data->structure->map)
		exit_error("Malloc error\n");
	line = get_next_line(data->map_fd);
	while (line)
	{
		if (ft_map_param(line) == 1 && ft_is_param(line) == 0)
		{
			//printf("line = %s\n", line);
			data->structure->map[i] = ft_strdup(line);
			//printf("map = %s\n", data->structure->map[i]);
			i++;
		}
		free(line);
		line = get_next_line(data->map_fd);
	}
	data->structure->map[i] = NULL;
	
	// int j;

	// j = 0;
	// while (data->structure->map[j] != NULL)
	// {
	// 	printf("map = %s\n", data->structure->map[j]);
	// 	j++;
	// }
	close(data->map_fd);
}



void	ft_get_map_size(t_data *data)
{
	char *line;
	
	//printf("cntl = %d\n", data->structure->cntl_map);
	data->map_fd = open(data->map_path, O_RDONLY);
	line = get_next_line(data->map_fd);

	// if (!ft_strchr(line, '1') && line[0] == '\n')
	// {
	// 	while (!ft_strchr(line, '1') && line[0] == '\n')
	// 	{
	// 		printf("line - %s", line);
	// 	free(line);
	// 	line = get_next_line(data->map_fd);
	// 	//data->structure->full_size++;
	// 	}
	// }
	// if (!ft_strchr(line, '1') && line[0] != '\n')
	// 	exit_error("Error\nBad map\n");

	while (line)
	{
		//printf("line = %s\n", line);
		//if (line == '1' || line == '0')
		//data->structure->full_size++;
		//printf("full_size %d\n", data->structure->full_size);
		// if (ft_is_param(line) == 1)
		// {
		// 	free(line);
		// 	line = get_next_line(data->map_fd);
		// }
			//printf("line len = %ld\n", ft_strlen(line));
			//printf("size_x = %d\n", data->structure->size_x);
		if (data->structure->cntl_map != 0 && (ft_is_param (line) == 0 || ft_empty_line(line) == 0))
		{
			
			//printf("size_x = %d\n", data->structure->size_x);}
			//printf("size_y = %d\n", data->structure->size_y);
			data->structure->size_y++;
			data->structure->cntl_map--;
		}
		else if (ft_is_param (line) == 0 && ft_empty_line(line) == 0)
		{
			if (ft_strlen(line) > (size_t)data->structure->size_x)
			{
				data->structure->size_x = ft_strlen(line);

			}
			data->structure->size_x++;
		}

		free(line);
		line = get_next_line(data->map_fd);
	}
	data->structure->size_y++;
	//printf("size_x = %d\n", data->structure->size_x);
	//printf("size_y = %d\n", data->structure->size_y);
	//free(line);
	close(data->map_fd);
}

void ft_validate_map(t_data *data)
{
	// int y;
	// int x;

	// y = 0;
	// while(data->structure->map[y] != NULL)
	// {
	// 	x = 0;
	// 	while(data->structure->map[y][x] != '\0')
	// 	{
	// 		// printf("y = %d\n", y);
	// 		// printf("x = %d\n", x);
	// 		// printf("last y = %d\n", ft_get_len(data->structure->map) - 1);
	// 		// printf("last x = %ld\n", ft_strlen(data->structure->map[y]) - 1);
	// 		//printf("x,y = %c\n", data->structure->map[y][x]);
	// 		if (data->structure->map[y][x] == '0')
	// 		{
	// 			// if ((data->structure->map[y][x + 1] == ' ' || data->structure->map[y][x - 1] == ' '
	// 			// || data->structure->map[y + 1][x] == ' ') || (data->structure->map[y - 1][x] == ' '
	// 			// || data->structure->map[y + 1][x + 1] == ' ') || (data->structure->map[y - 1][x - 1] == ' '
	// 			// || data->structure->map[y + 1][x - 1] == ' ' || data->structure->map[y - 1][x + 1] == ' '))
	// 			if (data->structure->map[y][x + 1] == ' ' || data->structure->map[y][x - 1] == ' '
	// 			|| data->structure->map[y + 1][x] == ' ' || data->structure->map[y - 1][x] == ' ')
	// 			{
	// 				exit_error("Invalid map, whitespaces inside map\n");
	// 			}
	// 		}
	// 		x++;
	// 	}
	// 	y++;
	// }
	ft_copy_map(data);
	ft_check_flood(data);
	//ft_print_map(data);
}
