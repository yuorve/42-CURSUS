/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:14:43 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/18 18:52:02 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_print_map(t_data *data)
{
	int i;

	i = 0;
	while (data->structure->copy_map[i] != NULL)
	{
		printf("copy_map = %s\n", data->structure->copy_map[i]);
		i++;
	}
}


int	ft_get_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}


// int ft_check_empty_line(char *line)
// {
// 	int i;

// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if ((line[i] == ' ' || line[i] == '	') && line[i] == '\n')
// 			{
// 				return (1);
// 			}
// 		i++;
// 	}
// 	return (0);
// }



void ft_check_file(t_data *data)
{
	ft_structure_check(data);
	ft_check_map_lines(data);
	ft_get_map_size(data);
	ft_check_map(data);
	ft_check_map_params(data);
	ft_validate_map(data);
}


void    ft_check_name(char *name, t_data *data)
{
	char	*path;
	int		len;

	len = (ft_strlen(name));
	if (ft_strncmp(name + (len - 4), ".cub", 4) == 0)
	{
		path = ft_strjoin("./assets/maps/", name);
		data->map_fd = open(path, O_RDONLY);
		if (data->map_fd == -1)
		{
			free(path);
            exit_error("Map not found\n");
		}
		else
		{
			data->map_path = ft_strdup(path);
			free(path);
		}
		close(data->map_fd);
	}
	else
		exit_error("Wrong name for the map\n");
}



void	ft_void(void)
{
	system("leaks -q 'cub3d'");
}

int main(int argc, char **argv)
{
    t_data data;

	atexit(ft_void);

	if (argc != 2)
	{
		exit_error("Wrong number of arguments\n");
	}
	ft_bzero(&data, sizeof(t_data));
	data.map = malloc(sizeof(t_map));
	data.structure = malloc(sizeof(t_structure));
	if (!data.map || !data.structure)
		return (0);
    ft_map_init(data.map);
	ft_structure_init(data.structure);
	ft_check_name(argv[1], &data);
	ft_check_file(&data);
	//ft_read_file(&data);
	//ft_get_map_size(&data);
	ft_free_structure(data.structure);

	// if (ft_read_file(&data) == 0)
	// {
	// 	ft_free_map(data.map);
	// 	free(data.map);
	// 	free(data.texture);
	// 	free(data.map_path);
	// 	return (0);
	// } 

	free(data.structure);
	free(data.map);
	free(data.map_path);  
	//free(&data);
	return (0);
}
