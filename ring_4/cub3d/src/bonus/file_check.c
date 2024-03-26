/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:56:02 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 18:26:28 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_param(char *line, t_data *data)
{
	char	**param;

	param = ft_split(line, ' ');
	ft_param_exists(data, param[0]);
	ft_get_param(data, param);
	data->structure->count_params++;
	ft_free_split(param);
}

void	ft_structure_check(t_data *data)
{
	char	*line;

	data->map_fd = open(data->map_path, O_RDONLY);
	if (data->map_fd == -1)
		exit_error("Map not found\n");
	line = get_next_line(data->map_fd);
	while (line)
	{
		data->structure->full_size++;
		if (ft_is_param(line) == 1)
		{
			ft_param(line, data);
		}
		ft_not_param(line, data);
		if (ft_map_param(line) == 1 && ft_is_param(line) == 0)
			data->structure->cntl_map ++;
		free(line);
		line = get_next_line(data->map_fd);
	}
	if (data->structure->count_params < 6)
		exit_error("Missing elements in the file\n");
	if (data->structure->cntl_map == 0)
		exit_error("Bad map\n");
	close(data->map_fd);
}

void	ft_check_empty_line_map(t_data *data, char *line)
{
	while (line)
	{
		if (line[0] == '\n' && ft_strlen(line) == 1)
			exit_error("Empty line in the map\n");
		else if (ft_empty_line(line) == 1 && ft_map_param(line) == 0
			&& ft_is_param(line) == 0)
			exit_error("Empty line in the map\n");
		free(line);
		line = get_next_line(data->map_fd);
	}
}

void	ft_check_map_lines(t_data *data)
{
	char	*line;

	data->map_fd = open(data->map_path, O_RDONLY);
	line = get_next_line(data->map_fd);
	while (line)
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
		free(line);
		line = get_next_line(data->map_fd);
	}
	ft_check_empty_line_map(data, line);
	close(data->map_fd);
}

int	ft_empty_line(char *line)
{
	int	i;
	int	cntl;

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
