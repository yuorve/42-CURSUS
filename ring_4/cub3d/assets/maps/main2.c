/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:14:43 by angalsty          #+#    #+#             */
/*   Updated: 2024/02/22 22:07:11 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(const char *message) 
{
    printf("Error\n%s\n", message);
    exit(EXIT_FAILURE);
}

void	ft_map_init(t_map *map) 
{
    map->n_rows = 0;
    map->n_lines = 0;
    map->n_player = 0;
    map->player.x = 0;
    map->player.y = 0;
    map->map = NULL;
}


void	ft_texture_start(t_texture *texture) 
{
	texture->NO = NULL;
	texture->SO = NULL;
	texture->WE = NULL;
	texture->EA = NULL;
	texture->F = NULL;
	texture->C = NULL;
}

void	ft_free_map(t_map *map) 
{
	int i;

	i = 0;
    while (i < map->n_rows) 
	{
        free(map->map[i]);
		i++;
    }
    free(map->map);
}

int	ft_rgb_texture(char **color)
{
	int i;
	
	i = -1;
	while (color[++i] != NULL)
	{
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
		{
			exit_error("Invalid color format of RGB\n");
			return (0);
		}
	}
	return (1);
}

void	ft_set_color(char ***color, char *line, int i)
{
	int j;
	int k;

	j = 0;
	k = -1;

	while (line[i] != '\0' && line[i] != '\n' && line[i] != '	' && line[i] != ' ')
	{
		if (line[i] == ',')
		{
			(*color)[j][++k] = '\0';
			j++;
			k = -1;
		}
		else
		{
			(*color)[j][++k] = line[i];
		}
		i++;
	}
	(*color)[j][++k] = '\0';
}

int	ft_number_correct(char *line, int i)
{
	int count;
	int cntl;

	count = 0;
	cntl = 1;
	while (line[i] != '\0' && line[i] != '\n' && line[i] != '	' && line[i] != ' ')
	{
		if (line[i] == ',')
			count++;
		else if(line[i] < '0' || line[i] > '9')
			cntl= 0;
		i++;
	}
	if (count != 2 || cntl == 0)
	{
		exit_error("Invalid color format of RGB\n");
		return (0);
	}
	return (1);
}

int	ft_init_color(char ***color, char *line, int i)
{
	int j;
	int k;

	if(ft_number_correct(line, i) == 0)
		return (0);
	//free(*color);
	(*color) = (char **) malloc (sizeof(char *) * 4);
	if (!(*color))
		return (0);
	k = -1;
	i--;
	while(++k < 3)
	{
		j = 0;
		while(line[++i] != ',' && line[i] != '\0' && line[i] != '\n' && line[i] != '	' && line[i] != ' ')
			j++;
		(*color)[k] = (char *) malloc (sizeof(char) * (j + 1));
		if (!(*color)[k])
			return (0);
	}
	(*color)[k] = NULL;
	return (1);
}

int ft_color(char ***color, char *line)
{
	int i;

	i = 1;
	while (line[i] == ' ' || line[i] == '	')
		i++;
	if(ft_init_color(color, line, i) == 0)
		return (0);
	ft_set_color(color, line, i);
	i = ft_rgb_texture(*color);
	return (i);
}

int ft_texture_path(char **texture, char *line)
{
	int i;
	int j;

	i = 2;
	while (line[i] == ' ' || line[i] == '	')
		i++;
	j = i;
	while (line[j] != '\0')
		j++;
	//free(*texture);
	(*texture) = (char *) malloc (sizeof(char) * (j - i + 1));
	if (!(*texture))
		return (0);
	j = -1;
	while (line[i] != '\0' && line[i] != '\n'
		&& line[i] != '	' && line[i] != ' ')
	{
		(*texture)[++j] = line[i];
		i++;
	}
	(*texture)[++j] = '\0';
	if(open((*texture), O_RDONLY) > 0)
		return (1);
	exit_error("texture dosent exist\n");
	return (0);
}

int	ft_texture_init(t_data *data, int **cntl_texture, char *line, int i)
{
	int	ctrl;

	ctrl = 1;
	while ((*cntl_texture)[i] != 0)
	{
		i++;
	}
	if ((*cntl_texture)[i] == 0)
	{
		(*cntl_texture)[i] = 1;
		if (i == 0)
		{
			if (data->texture->NO == NULL)
			{ctrl = (data->texture->NO || ft_texture_path(&data->texture->NO, line));
			printf("NO = %s\n", data->texture->NO);}
		}
		else if (i == 1)
			ctrl = ft_texture_path(&data->texture->SO, line);
		else if (i == 2)
			ctrl = ft_texture_path(&data->texture->WE, line);
		else if (i == 3)
			ctrl = ft_texture_path(&data->texture->EA, line);
		else if (i == 4)
			ctrl = ft_color(&data->texture->F, line);
		else if (i == 5)
			ctrl = ft_color(&data->texture->C, line);
	}
	else
	{
		ctrl = 0;
		exit_error("Extra texture parameter.");
	}
	return (ctrl);
}

int	ft_map(int *cntl_texture, int *cntl_map)
{
	int i;
	
	i = 0;
	while (i < 6)
	{
		if (cntl_texture[i] == 0)
		{
			exit_error("Texture parameter missing\n");
			return (0);
		}
		else if(i > 5)
		{
			exit_error("Texture parameter repeated\n");
			return (0);
		}
		printf("cntl_texture = %d\n", cntl_texture[i]);
		printf("i = %d\n", i);
		i++;
	}
	(*cntl_map) = 1;
	return (1);
}

int	ft_is_map(char *line, int *cntl_texture, int *cntl_map)
{
	int i;
	int cntl;

	i = -1;
	cntl = 1;
	while (line[++i] != '\0')
	{
		if(line[i] == '1' || line[i] == '0')
		{
			cntl = ft_map(cntl_texture, cntl_map);
			break;
		}
	}
	return(cntl);	
}

int	ft_map_texture(char *line, t_data *data, int *cntl_texture, int *cntl_map)
{
	int	ctrl;
	//int texture_count;

	ctrl = 0;
	//texture_count = 0;

	// while (texture_count < 6)
	// {
	// 	if ((ft_strncmp(line, "NO", 2) == 0) || (ft_strncmp(line, "SO", 2) == 0)
	// 	|| (ft_strncmp(line, "WE", 2) == 0) || (ft_strncmp(line, "EA", 2) == 0)
	// 	|| (ft_strncmp(line, "F", 1) == 0) || (ft_strncmp(line, "C", 1) == 0))
	// 	{
	// 		texture_count++;
	// 	}

	// }
	
	if (ft_strncmp(line, "NO", 2) == 0)
		ctrl = ft_texture_init(data, &cntl_texture, line, 0);
	else if (ft_strncmp(line, "SO", 2) == 0)
		ctrl = ft_texture_init(data, &cntl_texture, line, 1);
	else if (ft_strncmp(line, "WE", 2) == 0)
		ctrl = ft_texture_init(data, &cntl_texture, line, 2);
	else if (ft_strncmp(line, "EA", 2) == 0)
		ctrl = ft_texture_init(data, &cntl_texture, line, 3);
	else if (ft_strncmp(line, "F", 1) == 0)
		ctrl = ft_texture_init(data, &cntl_texture, line, 4);
	else if (ft_strncmp(line, "C", 1) == 0)
		ctrl = ft_texture_init(data, &cntl_texture, line, 5);
	else 
		ctrl = ft_is_map (line, cntl_texture, cntl_map);
	return (ctrl);
}

void	ft_read_map(char *line, t_data **data, int *cntl_map)
{
	int i;
	
	i = -1;
	if(*cntl_map == 1)
	{
		while (line[++i] != '\0')
		{
			if (line[i] == '1' || line[i] == '0')
			{
				(*data)->map->n_rows++;
				(*data)->map->n_lines = ft_strlen(line);
			}
		}
		//printf("n_rows = %d\n", (*data)->map->n_rows);
		//printf("n_lines = %d\n", (*data)->map->n_lines);
	}
}

char	*ft_parse_text(int fd, t_data *data, char *line, int cntl)
{
	int cntl_map;
	
	cntl_map = 1;
	while(line && cntl == 1)
	{
		ft_read_map(line, &data, &cntl_map);
		free(line);
		line = get_next_line(fd);
	}
	while(line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

char *get_param(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return ("NO");
	if (ft_strncmp(line, "SO", 2) == 0)
		return ("SO");
	if (ft_strncmp(line, "WE", 2) == 0)
		return ("WE");
	if (ft_strncmp(line, "EA", 2) == 0)
		return ("EA");
	if (ft_strncmp(line, "F", 1) == 0)
		return ("F");
	if (ft_strncmp(line, "C", 1) == 0)
		return ("C");
	return (NULL);
}

int ft_is_map_line(char *line)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' && line[i] != '	'
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W' && line[i] != 'E')
			return (0);
	}
	return (1);
}

int ft_all_params_initialized(t_data *data)
{
	if (data->texture->NO == NULL || data->texture->SO == NULL
		|| data->texture->WE == NULL || data->texture->EA == NULL
		|| data->texture->F == NULL || data->texture->C == NULL)
		return (0);
	return (1);
}

int ft_param_initialized(char *line, t_data *data)
{
	char *param;

	param = get_param(line);
	if ((ft_strncmp(param, "NO", 2) == 0 && data->texture->NO != NULL)
		|| (ft_strncmp(param, "SO", 2) == 0 && data->texture->SO != NULL)
		|| (ft_strncmp(param, "WE", 2) == 0 && data->texture->WE != NULL)
		|| (ft_strncmp(param, "EA", 2) == 0 && data->texture->EA != NULL)
		|| (ft_strncmp(param, "F", 1) == 0 && data->texture->F != NULL)
		|| (ft_strncmp(param, "C", 1) == 0 && data->texture->C != NULL))
		return (1);
	return (0);
}

int ft_is_param(char *line)
{
	return (
		(ft_strncmp(line, "NO", 2) == 0) || (ft_strncmp(line, "SO", 2) == 0)
		|| (ft_strncmp(line, "WE", 2) == 0) || (ft_strncmp(line, "EA", 2) == 0)
		|| (ft_strncmp(line, "F", 1) == 0) || (ft_strncmp(line, "C", 1) == 0)
	);
}

char **get_param_address(char *param, t_data *data)
{
	if (ft_strncmp(param, "NO", 2) == 0)
		return (&data->texture->NO);
	if (ft_strncmp(param, "SO", 2) == 0)
		return (&data->texture->SO);
	if (ft_strncmp(param, "WE", 2) == 0)
		return (&data->texture->WE);
	if (ft_strncmp(param, "EA", 2) == 0)
		return (&data->texture->EA);
	if (ft_strncmp(param, "F", 1) == 0)
		return (data->texture->F);
	if (ft_strncmp(param, "C", 1) == 0)
		return (data->texture->C);
	return (NULL);
}

int	ft_parse_file(int fd, t_data *data)
{
	char	*param;
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		exit_error("Map is empty.");
	while(line)
	{
		if (line[0] == '\0' || line[0] == '\n')
		{
			free(line);
			line = get_next_line(fd);
			continue;
		}
		param = get_param(line);
		if (param)
		{
			if (ft_param_initialized(line, data))
				exit_error("Texture parameter repeated.");
				
			ft_texture_path(get_param_address(param, data), line);
		}
		else if (!ft_all_params_initialized(data))
			exit_error("Texture parameter missing.");
		else
		{
			if (!ft_is_map_line(line))
				exit_error("Invalid map line.");
			// ft_parse_text(fd, data, line, 1);
			// break;
		}
		free(line);
		line = get_next_line(fd);
	
	}
	return (1);
}

// int	ft_parse_file(int fd, t_data *data, char *line)
// {
// 	int	cntl;
// 	int	i;
// 	int cntl_map;
// 	int cntl_texture[6];
	
// 	cntl = 1;
// 	i = -1;
// 	cntl_map = 0;
// 	while (++i < 6)
// 		cntl_texture[i] = 0;
// 	while (line && cntl == 1)
// 	{
// 		cntl = ft_map_texture(line, data, cntl_texture, &cntl_map);
// 		//cntl_map tiene que ser 0 para que se ejecute el parseo del mapa
// 		//cntl tiene que ser 1 para que se ejecute el parseo del mapa
// 		if (cntl_map == 1 && cntl == 1)
// 			break ;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	line = ft_parse_text(fd, data, line, cntl);
// 	free(line);
// 	// if (cntl == 1)
// 	// 	cntl = ft_parse_map(fd, data);
// 	return (cntl);
// }

int	ft_read_file(t_data *data)
{
	int fd;
    // char *line;
	int cntl;

	if (open(data->map_path, O_RDONLY) > 0)
	{
		cntl = 1;
    	fd = open(data->map_path, O_RDONLY);
		// line = get_next_line(fd);
		// if (line == NULL)
		// 	exit_error("Map is empty.");
		// cntl = ft_parse_file(fd, data, line);
		cntl = ft_parse_file(fd, data);
		close(fd);
	}
	else
	{
		exit_error("Map not found");
		cntl = 0;
	}
	return (cntl);
}


void    ft_check_name(char *name, t_data *data)
{
    int		fd;
	char	*path;
	int		len;

	len = (ft_strlen(name));
	if (ft_strncmp(name + (len - 4), ".cub", 4) == 0)
	{
		path = ft_strjoin("./assets/maps/", name);
		fd = open(path, O_RDONLY);
		if (fd == -1)
		{
			free(path);
            exit_error("Map not found");
		}
		else
		{
			data->map_path = ft_strdup(path);
			free(path);
		}
		close(fd);
	}
	else
		exit_error("Wrong name for the map");
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	data->map = malloc(sizeof(t_map));
	data->texture = malloc(sizeof(t_texture));
	if (!data->map || !data->texture)
		return ;
    ft_map_init(data->map);
	ft_texture_start(data->texture);
}

int main(int argc, char **argv)
{
    t_data data;

	if (argc != 2)
	{
		exit_error("Wrong number of arguments");
	}

	init_data(&data);
	ft_check_name(argv[1], &data);
    //ft_create_map(&data);

	if (ft_read_file(&data) == 0)
	{
		ft_free_map(data.map);
		free(data.map);
		free(data.texture);
		free(data.map_path);
		return (0);
	}  
	//free(&data);  
	return (0);
}
