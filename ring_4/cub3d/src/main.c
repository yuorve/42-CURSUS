/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:14:43 by angalsty          #+#    #+#             */
/*   Updated: 2024/03/23 18:10:53 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_file(t_data *data)
{
	ft_structure_check(data);
	ft_check_map_lines(data);
	ft_get_map_size(data);
	ft_check_map(data);
	ft_check_map_params(data);
	ft_validate_map(data);
}

void	ft_check_name(char *name, t_data *data)
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

int32_t	main(int argc, char **argv)
{
	t_data	*data;

	atexit(ft_void);
	if (argc != 2)
	{
		exit_error("Wrong number of arguments\n");
	}
	data = calloc(1, sizeof(t_data));
	data->wall = calloc(1, sizeof(t_wall));
	data->ply = calloc(1, sizeof(t_player));
	data->ply->pos = calloc(1, sizeof(t_point));
	data->ray = calloc(1, sizeof(t_ray));
	data->map = calloc(1, sizeof(t_map));
	data->structure = calloc(1, sizeof(t_structure));
	ft_map_init(data->map);
	ft_structure_init(data->structure);
	ft_check_name(argv[1], data);
	ft_check_file(data);
	data->map->width = data->structure->size_x;
	data->map->height = data->structure->size_y;
	data->map->matrix = data->structure->map;
	data->mlx = mlx_init(S_W, S_H, "Cube 3D - Play it!", true);
	ft_load_texture(data);
	ft_player_init(data);
	mlx_key_hook(data->mlx, &ft_keys_hook, data);
	mlx_loop_hook(data->mlx, &ft_game, data);
	mlx_loop_hook(data->mlx, &ft_minimap, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	ft_free_structure(data->structure);
	free(data->structure);
	free(data->map);
	free(data->map_path);
	ft_free(data);
	return (0);
}
