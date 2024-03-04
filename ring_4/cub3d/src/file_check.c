/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:56:02 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/04 21:26:38 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_structure_check(t_data *data)
{
	char *line;
	char **param;


	//printf("cntl = %d\n", data->structure->cntl_map);
	data->map_fd = open(data->map_path, O_RDONLY);
	if (data->map_fd == -1)
	{
		exit_error("Map not found\n");
	}
	line = get_next_line(data->map_fd);
	while (line)
	{
		//printf("line %s\n", line);
		data->structure->full_size++;
		//printf("full_size = %d\n", data->structure->full_size);
		if (ft_is_param(line) == 1)
		{
			param = ft_split(line, ' ');
			ft_param_exists(data, param[0]);
			ft_get_param(data, param);
			data->structure->count_params++;
			free_split(param);
			//printf("count_param = %d\n", data->structure->count_params);
		}
		ft_not_param(line, data);
		if (ft_map_param(line) == 1 && ft_is_param(line) == 0)
			{
				data->structure->cntl_map ++;
			}
		// if (split_size(param) < 2
		// && ft_strncmp(param[0], "\n", ft_strlen(param[0])))
		// 		exit_error("Error\nMissing elements\n");
			//if (!ft_strchr(param[0], '\n'))
			//{
				//ft_get_param(data, param);
				// if (data->structure->count_params > 6)
				// 	ft_param_exists(data, param[0]);
				//ft_param_path(data, param[1]);
				//data->structure->count_params++;
				//printf("count_param = %d\n", data->structure->count_params);
			//}
				free(line);
			line = get_next_line(data->map_fd);
	}	
	// if (data->structure->count_params > 6)
	// 	exit_error("Too many elements in the file\n");

	if (data->structure->count_params < 6)
		exit_error("Missing elements in the file\n");
	if (data->structure->cntl_map == 0)
		exit_error("Bad map\n");
	close(data->map_fd);
}



void ft_check_empty_line_map(t_data *data, char *line)
{
	while (line)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
			exit_error("Empty line in the map\n");
		else if (ft_empty_line(line) == 1 && ft_map_param(line) == 0 && ft_is_param(line) == 0)
			exit_error("Empty line in the map\n");
		//printf("line = %s\n", line);
		free(line);
		line = get_next_line(data->map_fd);
	}
}

void ft_check_map_lines(t_data *data)
{
	char *line;


	data->map_fd = open(data->map_path, O_RDONLY);
	line = get_next_line(data->map_fd);
	while(line)
	{
		if (ft_is_param(line) == 1 && ft_empty_line(line) == 1)
		{
			free(line);
			line = get_next_line(data->map_fd);
		}
		else if (ft_map_param(line) == 1)
		{
			break ;
		}
		//printf("line = %s\n", line);
		free(line);
		line = get_next_line(data->map_fd);
	}
	ft_check_empty_line_map(data, line);

	close(data->map_fd);
}

int ft_empty_line(char *line)
{
	int i;
	int cntl;

	i = 0;
	cntl = 0;

	if (line[i] == ' ' || line[i] == '	' || line[i] == '\n')
	{
		while (line[i] != '\0')
		{
			if (line[i] == ' ' || line[i] == '	' || line[i] == '\n')
			cntl = 1;
			i++;
		}
	}
	return (cntl);
}