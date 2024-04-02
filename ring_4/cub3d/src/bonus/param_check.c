/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:35:16 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/25 17:49:51 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_param_path(char *path)
{
	int		i;
	char	*str;

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
	return (str);
}

void	ft_get_param(t_data *data, char **param)
{
	if (ft_strncmp(param[0], "NO", 2) == 0)
		ft_process_texture(data, param, &data->structure->no);
	else if (ft_strncmp(param[0], "SO", 2) == 0)
		ft_process_texture(data, param, &data->structure->so);
	else if (ft_strncmp(param[0], "WE", 2) == 0)
		ft_process_texture(data, param, &data->structure->we);
	else if (ft_strncmp(param[0], "EA", 2) == 0)
		ft_process_texture(data, param, &data->structure->ea);
	else if (ft_strncmp(param[0], "F", 1) == 0)
		ft_process_color(data, param, &data->structure->f);
	else if (ft_strncmp(param[0], "C", 1) == 0)
		ft_process_color(data, param, &data->structure->c);
	else
	{
		ft_free_split(param);
		exit_error("Missing elements\n");
	}
}

void	ft_param_exists(t_data *data, char *param)
{
	if (ft_strncmp(param, "NO", 2) == 0)
		ft_check_texture_exists(data->structure->no);
	else if (ft_strncmp(param, "SO", 2) == 0)
		ft_check_texture_exists(data->structure->so);
	else if (ft_strncmp(param, "WE", 2) == 0)
		ft_check_texture_exists(data->structure->we);
	else if (ft_strncmp(param, "EA", 2) == 0)
		ft_check_texture_exists(data->structure->ea);
	else if (ft_strncmp(param, "F", 1) == 0)
		ft_check_color_exists(data->structure->f);
	else if (ft_strncmp(param, "C", 1) == 0)
		ft_check_color_exists(data->structure->c);
}

void	ft_not_param(char *line, t_data *data)
{
	if ((ft_strncmp(line, "NO", 2) == 0) || (ft_strncmp(line, "SO", 2) == 0)
		|| (ft_strncmp(line, "WE", 2) == 0) || (ft_strncmp(line, "EA", 2) == 0)
		|| (ft_strncmp(line, "F", 1) == 0) || (ft_strncmp(line, "C", 1) == 0))
	{
		return ;
	}
	else if (ft_empty_line(line) == 1)
	{
		return ;
	}
	else if (ft_map_param(line) == 1)
	{
		if (data->structure->count_params == 6)
		{
			return ;
		}
		else
			exit_error("Missing elements\n");
	}
	else
	{
		exit_error("Wrong parameter in the map file\n");
		return ;
	}
}

int	ft_is_param(char *line)
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
