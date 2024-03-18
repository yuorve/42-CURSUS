/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:14:43 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/18 19:17:47 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int32_t main(int argc, char **argv)
{
    t_data *data;

	atexit(ft_void);

	if (argc != 2)
	{
		exit_error("Wrong number of arguments\n");
	}
	//ft_bzero(&data, sizeof(t_data));
	data = calloc(1, sizeof(t_data));
	data->wall = calloc(1, sizeof(t_wall));
	data->ply = calloc(1, sizeof(t_player));
	data->ply->pos = calloc(1, sizeof(t_point));
	data->ray = calloc(1, sizeof(t_ray));
	data->map = calloc(1, sizeof(t_map));
	data->structure = calloc(1, sizeof(t_structure));
	//data.map = malloc(sizeof(t_map));
	//data.structure = malloc(sizeof(t_structure));
	// if (!data.map || !data.structure)
	// 	return (0);
    ft_map_init(data->map);
	ft_structure_init(data->structure);
	ft_check_name(argv[1], data);
	ft_check_file(data);
	//read_map(data);
	//data->map->width = data->structure->size_x;
	printf("data->structure->size_x: %d\n", data->structure->size_x);
	printf("data->structure->size_y: %d\n", data->structure->size_y);
	data->map->height = data->structure->size_y;
	data->map->matrix = data->structure->map;
	data->mlx = mlx_init(S_W, S_H, "Cube 3D - Play it!", true);
	ft_load_texture(data);
	ft_draw_scene(data);
	ft_player_init(data);
	ft_player(data);
	mlx_key_hook(data->mlx, &ft_keys_hook, data);
	mlx_loop_hook(data->mlx, &ft_game, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	free(data->map->file);
	//ft_read_file(&data);
	//ft_get_map_size(&data);
	ft_free_structure(data->structure);

	// if (ft_read_file(&data) == 0)
	// {
	// 	ft_free_map(data.map);
	// 	free(data.map);
	// 	free(data.texture);
	// 	free(data.map_path);
	// 	return (0);
	// } 

	free(data->structure);
	free(data->map);
	free(data->map_path);  
	//free(&data);
	return (0);
}
