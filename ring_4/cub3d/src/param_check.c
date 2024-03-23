/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:35:16 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 15:22:47 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

char *ft_param_path(char *path)
{
	int i;
	char *str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(path) + 1));
	while (path[i] != '\0')
	{
		if (path[i] == ' ' || path[i] == '	' || path[i] == '\n')
			break ;
		str[i] = path[i];
		i++;
	}
	str[i] = '\0';

    if (access(str, F_OK) != 0) 
	{
        exit_error("Texture file not found\n");
    }
	//free(str);
	return(str) ;
}


void  ft_get_param(t_data *data, char **param)
{
	// if (split_size(param) != 2)
	// 	exit_error("Wrong elements\n");
	
	// if (check_tags(data, param[0]))
	// 	exit_error("Overwritting elements\n");
	if (ft_strncmp(param[0], "NO", 2) == 0)
		{
			//ft_param_path(param[1]);
			if (param[2] != NULL && ft_empty_line(param[2]) == 0)
				exit_error("Wrong elements in the path\n");
			data->structure->NO = ft_param_path(param[1]);
		}
	else if (ft_strncmp(param[0], "SO", 2) == 0)
		{
			//ft_param_path(param[1]);
			if (param[2] != NULL && ft_empty_line(param[2]) == 0)
				exit_error("Wrong elements in the path\n");
			data->structure->SO = ft_param_path(param[1]);
		}
	else if (ft_strncmp(param[0], "WE", 2) == 0)
		{
			//ft_param_path(param[1]);
			if (param[2] != NULL && ft_empty_line(param[2]) == 0)
				exit_error("Wrong elements in the path\n");
			data->structure->WE = ft_param_path(param[1]);
		}
	else if (ft_strncmp(param[0], "EA", 2) == 0)
		{
			//ft_param_path(param[1]);
			if (param[2] != NULL && ft_empty_line(param[2]) == 0)
				exit_error("Wrong elements in the path\n");
			data->structure->EA = ft_param_path(param[1]);
		}
	else if (ft_strncmp(param[0], "F", 1) == 0)
	{
		data->structure->F = ft_check_color(param[1]);
		if (param[2] != NULL && ft_empty_line(param[2]) == 0)
			exit_error("Wrong elements in the color\n");
	}
	else if (ft_strncmp(param[0], "C", 1) == 0)
	{
		data->structure->C = ft_check_color(param[1]);
		if (param[2] != NULL && ft_empty_line(param[2]) == 0)
			exit_error("Wrong elements in the path\n");
	}
	else
	{
		ft_free_split(param);
		exit_error("Missing elements\n");
	}
}

void	ft_param_exists(t_data *data, char *param)
{
	if (ft_strncmp(param, "NO", 2) == 0)
	{
		if (data->structure->NO != NULL)
			exit_error("Element is repeated\n");
	}
	else if (ft_strncmp(param, "SO", 2) == 0)
	{
		if (data->structure->SO != NULL)
			exit_error("Element is repeated\n");
	}
	else if (ft_strncmp(param, "WE", 2) == 0)
	{
		if (data->structure->WE != NULL)
			exit_error("Element is repeated\n");
	}
	else if (ft_strncmp(param, "EA", 2) == 0)
	{
		if (data->structure->EA != NULL)
			exit_error("Element is repeated\n");
	}
	else if (ft_strncmp(param, "F", 1) == 0)
	{
		if (data->structure->F != 0)
			exit_error("Element is repeated\n");
	}
	else if (ft_strncmp(param, "C", 1) == 0)
	{
		if (data->structure->C != 0)
			exit_error("Element is repeated\n");
	}
}

void	ft_not_param(char *line, t_data *data)
{
	if ((ft_strncmp(line, "NO", 2) == 0) || (ft_strncmp(line, "SO", 2) == 0)
		|| (ft_strncmp(line, "WE", 2) == 0) || (ft_strncmp(line, "EA", 2) == 0)
		|| (ft_strncmp(line, "F", 1) == 0) || (ft_strncmp(line, "C", 1) == 0))
	{
		//printf("param\n");
		return ;
	}
	else if (ft_empty_line(line) == 1)
	{
		//printf("empty line\n");
		return ;
	}
	else if (ft_map_param(line) == 1)
	{
		if (data->structure->count_params == 6)
		{
			return ;
			//printf("map_start = %d\n", data->structure->map_start);
		}
		else
			exit_error("Missing elements\n");
			//printf("got the map\n");
	}
	else
	{
		//printf("not param\n");
		exit_error("Wrong parameter in the map file\n");
		return ;
	}
	
}

int ft_is_param(char *line)
{

	if (ft_strncmp(line, "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "F", 1) == 0)
		return (1);
	else if (ft_strncmp(line, "C", 1) == 0)
		return (1);
	else
	return (0);
}