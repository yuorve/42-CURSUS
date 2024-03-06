/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:14:43 by angalsty          #+#    #+#             */
/*   Updated: 2024/02/16 22:08:52 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	ft_map_init(t_data *data)
// {
// 	data->map->n_rows = 0;
// 	data->map->n_lines = 0;
// 	data->map->n_player = 0;
// 	data->map->player.x = 0;
// 	data->map->player.y = 0;
// }

// void	ft_read_map(t_data *data)
// {
// 	int		fd;
// 	int     line;
// 	int		i;
// 	char *new_line;

// 	line = 0;
// 	fd = open(data->map_path, O_RDONLY);
// 	new_line = get_next_line(fd);
// 	while (new_line != NULL)
// 	{
// 		line++;
// 		free(new_line);
// 		new_line = get_next_line(fd);
// 	}
// 		i = 0;
// 		while (new_line[i])
// 		{
// 			if (new_line[i] == 'N' || new_line[i] == 'S' || new_line[i] == 'E' || new_line[i] == 'W')
// 			{
// 				data->n_player++;
// 				data->player.x = i;
// 				data->player.y = line;
// 			}
// 			i++;
// 		}
// 		data->map_height = line;
// 		data->map_width = i;
// 		free(new_line);
// 		close(fd);
// }

// void    ft_create_map(t_data *data)
// {
//     ft_map_init(data);
//     //ft_read_map(data);
//     //ft_check_map(data);
// }

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


int	ft_parse_map(int fd, t_data *data)
{
	char *line;
	int len;
	int i;
	int ctrl;

	i = 0;
	ctrl = 1;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > data->map->n_lines)
			data->map->n_lines = len;
		data->map->n_rows++;
		i++;
		free(line);
		line = get_next_line(fd);
	}
	data->map->map = malloc(sizeof(char *) * data->map->n_rows);
	if (data->map->map == NULL)
	{
		exit_error("Failed to allocate memory for the map.");
		ctrl = 0;
	}
	i = 0;
	while (i < data->map->n_rows)
	{
		data->map->map[i] = malloc(sizeof(char) * (data->map->n_lines + 1));
		if (data->map->map[i] == NULL)
		{
			exit_error("Failed to allocate memory for the map.");
			ctrl = 0;
		}
		i++;
	}
	return (ctrl);
}
// {
// 	int len;
// 	int i;
	
// 	len = ft_strlen(line);
// 	// printf("len = %d\n", len);
// 	i = 0;
//     // Validate the characters in the map
//     while (i < len - 1) 
// 	{
//         if (line[i] != ' ' && line[i] != '1' && line[i] != '0' &&
//             line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W') 
//             exit_error("Invalid character in the map.");

//         // Track player's position
//         if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W') 
// 		{
//             data->map->n_player++;
//             data->map->player.x = i;
//             data->map->player.y = data->map->n_lines;
// 			// printf("player = %d\n", data->map->n_player);
// 			// printf("player.x = %d", data->map->player.x);
// 			// printf("player.y = %d\n", data->map->player.y);
//         }

// 		// printf("line[i] = %c\n", line[i]);
// 		// printf("i = %d\n", i);
// 		i++;
//     }

//     //Validate the map being surrounded by walls
//     if (line[0] != '1' || line[len - 2] != '1') 
//         exit_error("Map should be surrounded by walls.");
// }

// int	ft_texture_path(char **texture, char *line)
// {
// 	int	i;
// 	int	j;

// 	i = 2;
// 	while (line[i] == ' ' || line[i] == '	')
// 		i++;
// 	j = i;
// 	while (line[j] != '\0')
// 	{printf("here\n");
// 		j++;}
// 	free(*texture);
// 	(*texture) = (char *) malloc (sizeof(char) * (j - i + 1));
// 	if (!(*texture))
// 		return (0);
// 	j = -1;
// 	while (line[i] != '\0' && line[i] != '\n'
// 		&& line[i] != '	' && line[i] != ' ')
// 	{
// 		(*texture)[++j] = line[i];
// 		i++;
// 	}
// 	(*texture)[++j] = '\0';
// 	if (open((*texture), O_RDONLY) > 0)
// 		return (1);
// 	printf("Error: texture dosent exist\n");
// 	return (0);
// }

// int	ft_texture_path(char **texture, char *line)
// {
//     int i = 2;
//     int j = 0;

//     // Skip leading spaces or tabs
//     while (line[i] == ' ' || line[i] == '\t')
//         i++;
// 		printf("i = %d\n", i);

//     // Find the length of the texture path
//     while (line[i + j] && line[i + j] != '\n' && line[i + j] != '\t' && line[i + j] != ' ')
//         j++;
// 		printf("j = %d\n", j);

//     // Allocate memory for the texture path
//     *texture = (char *)malloc(sizeof(char) * (j + 1));
//     // if (!(*texture))
//     //     return (0);
// 		printf("here\n");

//     // Copy the texture path
//     j = 0;
//     while (line[i] && line[i] != '\n' && line[i] != '\t' && line[i] != ' ')
//         (*texture)[j++] = line[i++];
//     (*texture)[j] = '\0'; // Null-terminate the string

//     // Attempt to open the texture file
//     int fd = open(*texture, O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error: Texture file '%s' does not exist\n", *texture);
//         free(*texture);
//         return (0);
//     }
// 	free(*texture);
//     close(fd);
//     return (1);
// }

// int	ft_texture_init(t_data *data, int *data_len, char *line, int i)
// {
// 	int cntl;

// 	cntl = 1;

// 	// if(ft_strncmp(line, "NO", 2) == 0)
// 	// {
// 	// 	if (data_len[0] == 0)
// 	// 	{
// 	// 		data_len[0] = 1;
// 	// 		cntl = ft_texture_path(data->texture->NO, line);
// 	// 	}
// 	// }
// 	// else if(ft_strncmp(line, "SO", 2) == 0)
// 	// {
// 	// 	if (data_len[1] == 0)
// 	// 	{
// 	// 		data_len[1] = 1;
// 	// 		cntl = ft_texture_path(data->texture->SO, line);
// 	// 	}
// 	// }
// 	// else if(ft_strncmp(line, "WE", 2) == 0)
// 	// {
// 	// 	if (data_len[2] == 0)
// 	// 	{
// 	// 		data_len[2] = 1;
// 	// 		cntl = ft_texture_path(data->texture->WE, line);
// 	// 	}
// 	// }
// 	// else if(ft_strncmp(line, "EA", 2) == 0)
// 	// {
// 	// 	if (data_len[3] == 0)
// 	// 	{
// 	// 		data_len[3] = 1;
// 	// 		cntl = ft_texture_path(data->texture->EA, line);
// 	// 	}
// 	// }
// 	// else if(ft_strncmp(line, "F", 1) == 0)
// 	// {
// 	// 	if (data_len[4] == 0)
// 	// 	{
// 	// 		data_len[4] = 1;
// 	// 		cntl = ft_texture_path(data->texture->F, line);
// 	// 	}
// 	// }
// 	// else if(ft_strncmp(line, "C", 1) == 0)
// 	// {
// 	// 	if (data_len[5] == 0)
// 	// 	{
// 	// 		data_len[5] = 1;
// 	// 		cntl = ft_texture_path(data->texture->C, line);
// 	// 	}
// 	// }
// 	// else
// 	// {
// 	// 	cntl = 0;
// 	// 	exit_error("Error: Extra texture parameter.");
// 	// }
	
// 	if(data_len[i] == 0)
// 	{
// 		data_len[i] = data_len[i] + 1;
// 		if (i == 0)
// 			cntl = ft_texture_path(&data->texture->NO, line);
// 		else if (i == 1)
// 			cntl = ft_texture_path(&data->texture->SO, line);
// 		else if (i == 2)
// 			cntl = ft_texture_path(&data->texture->WE, line);
// 		else if (i == 3)
// 			cntl = ft_texture_path(&data->texture->EA, line);
// 		else if (i == 4)
// 			cntl = ft_texture_path(&data->texture->F, line);
// 		else if (i == 5)
// 			cntl = ft_texture_path(&data->texture->C, line);
// 	}
// 	else
// 	{
// 		cntl = 0;
// 		exit_error("Error: Extra texture parameter.");
// 	}
// 	return (cntl);
// }


// int ft_is_map(char *line, int data_len, int map_len)
// {
// 	int len;
// 	int i;
// 	int ctrl;

// 	len = ft_strlen(line);
// 	i = 0;
// 	ctrl = 1;
// 	while (i < len)
// 	{
// 		if (line[i] != ' ' && line[i] != '1' && line[i] != '0' &&
// 			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W') 
// 		{
// 			ctrl = 0;
// 			break ;
// 		}
// 		i++;
// 	}
// 	if (ctrl == 0)
// 		exit_error("Invalid character in the map.");
// 	if (data_len == 0)
// 		exit_error("Map should be surrounded by walls.");
// 	if (map_len == 1)
// 		exit_error("Map should be surrounded by walls.");
// 	return (ctrl);
// }




// char	*ft_parse_text(int fd, t_data *data, char *line, int cntl)
// {
// 	int len;
// 	int i;
// 	int data_len[6];
// 	int map_len;
	
// 	len = 0;
// 	map_len = 0;
// 	i = 0;
// 	while (i < 6)
// 	{
// 		data_len[i] = 0;
// 		i++;
// 	}
// 	while (line && cntl == 1)
// 	{
// 		cntl = ft_map_data(line, data, data_len, &map_len);
// 		if (map_len == 1)
// 			break ;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	return (line);
// }

// int	ft_parse_file(int fd, t_data *data, char *line)
// {
// 	int cntl;
// 	int i;
// 	int map_len;
// 	int data_len[6];
	
// 	cntl = 1;
// 	map_len = 0;
// 	i = -1;
// 	while (++i < 6)
// 	{
// 		data_len[i] = 0;
// 		printf("data_len[%d] = %d\n", i, data_len[i]);
// 	}
// 	while (line && cntl == 1)
// 	{
// 		cntl = ft_map_data(line, data, data_len, &map_len);
// 		if (map_len == 1)
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

// int ft_parse_file(int fd, t_data *data, char *line)
// {
// 	int cntl;
// 	(void)fd;
	

// 	cntl = 1;
// 	while (line && cntl == 1)
// 	{
		
// 	}
// 	return (cntl);
// }

// int	ft_read_map(t_data *data)
// {
// 	int fd;
//     char *line;
// 	int cntl;
// 	int i = 0;
	
//     fd = open(data->map_path, O_RDONLY);
//     if (fd == -1)
// 	{ 
//         exit_error("Failed to open the map file.");
// 		cntl = 0;
// 	}
// 	cntl = 1;
// 	line = get_next_line(fd);
// 	if (line == NULL)
// 	{
// 		exit_error("Map is empty.");
// 	}
// 	while (line)
// 	{
// 		if (line[0] == '\0' || line[0] == '\n') 
//             continue;
// 		//ft_parse_map(line, data);
// 		//cntl = ft_parse_file(fd, data, line);
// 		printf("i = %d\n", i);
// 		i++;
// 		free(line);
// 		//line = get_next_line(fd);
// 	}
//     if (data->map->n_player != 1) 
//         exit_error("Map should have exactly one player.");
		
//     // Check for additional conditions
//     close(fd);
//     // if (line)
// 	// 	free(line);
// 	return (cntl);
// }

// int ft_texture_path(char **texture, char *line)
// {
//     int i = 3; // Índice para saltar el identificador y el espacio inicial
//     int j = 0; // Índice para la nueva cadena de texto

//     // Saltar espacios iniciales
//     while (line[i] == ' ' || line[i] == '\t')
//     {
//         i++;
//     }

//     // Determinar la longitud de la ruta de la textura
//     while (line[i + j] && line[i + j] != ' ' && line[i + j] != '\t' && line[i + j] != '\n')
//     {
//         j++;
//     }

//     // Asignar memoria para la nueva cadena de texto
//     // *texture = (char *)malloc(sizeof(char) * (j + 1));
//     // if (!*texture)
//     // {
//     //     return 0; // Error al asignar memoria
//     // }

//     // Copiar la ruta de la textura a la nueva cadena de texto
//     j = 0;
//     while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
//     {
//         (*texture)[j] = *ft_strdup(&line[i]);
//         i++;
//         j++;
// 	printf("I am here\n");
//     }
//     (*texture)[j] = '\0'; // Terminar la cadena con el carácter nulo

//     // Verificar si el archivo de la textura existe
//     // int fd = open(*texture, O_RDONLY);
//     // if (fd == -1)
//     // {
//     //     free(*texture); // Liberar la memoria asignada
//     //     *texture = NULL; // Establecer el puntero a NULL
//     //     close(fd); // Cerrar el archivo
//     //     return 0; // Error: no se pudo abrir el archivo
//     // }
//     // close(fd); // Cerrar el archivo

//     return 1; // La ruta de la textura es válida
// }


// int ft_parse_file(int fd, t_data *data, char *line)
// {
// 	int cntl = 1;
//     int flag = 0;
// 	(void)fd;
//     //int text_len[6] = {0}; // Inicializamos a 0

//     while (line && cntl == 1)
//     {
//         if (line[0] != '\0' && line[0] != '\n')
//         {
//             // Si encontramos una línea en blanco, cambiamos la bandera para indicar que pasamos a la sección de mapa
//             if (line[0] == '\r' || line[0] == ' ')
//                 flag = 1;

//             if (flag == 0) // Si estamos en la sección de texturas
//             {
//                 // Analizar y procesar las líneas de texturas
//                 if (ft_strncmp(line, "NO ", 3) == 0)
//                 {
//                     if (!ft_texture_path(&data->texture->NO, line))
//                         cntl = 0; // Error al procesar la textura
//                 }
//                 else if (ft_strncmp(line, "SO ", 3) == 0)
//                 {
//                     if (!ft_texture_path(&data->texture->SO, line))
//                         cntl = 0; // Error al procesar la textura
//                 }
//                 else if (ft_strncmp(line, "WE ", 3) == 0)
// 				{
// 					if (!ft_texture_path(&data->texture->WE, line))
// 						cntl = 0; // Error al procesar la textura
// 				}
// 				else if (ft_strncmp(line, "EA ", 3) == 0)
// 				{
// 					if (!ft_texture_path(&data->texture->EA, line))
// 						cntl = 0; // Error al procesar la textura
// 				}
// 				else if (ft_strncmp(line, "F ", 2) == 0)
// 				{
// 					if (!ft_texture_path(&data->texture->F, line))
// 						cntl = 0; // Error al procesar la textura
// 				}
// 				else if (ft_strncmp(line, "C ", 2) == 0)
// 				{
// 					if (!ft_texture_path(&data->texture->C, line))
// 						cntl = 0; // Error al procesar la textura
// 				}
// 			}
//             else // Si estamos en la sección de mapa
//             {
// 				printf("we are in the map\n");
//                 // Procesar las líneas que representan el mapa
//                 // Aquí puedes llamar a una función que analice las líneas del mapa y las agregue a la estructura de datos
//                 // Por ejemplo:
//                 // if (!parse_map_line(line, data))
//                 // {
//                 //     cntl = 0; // Error al procesar una línea del mapa
//                 // }
//             }
//         }
//         //free(line);
//         //line = get_next_line(fd);
//     }
//     return cntl;	
// }

// int	ft_read_map(t_data *data)
// {
// 	int fd;
//     char *line;
// 	int cntl;
// 	int line_count = 0;
	
//     fd = open(data->map_path, O_RDONLY);
//     if (fd == -1)
// 	{ 
//         exit_error("Failed to open the map file.");
// 		cntl = 0;
// 	}

// 	line = get_next_line(fd);
// 	if (line == NULL)
// 	{
// 		exit_error("Map is empty.");
// 	}

// 	while (line)
// 	{
// 		if (line[0] != '\0' && line[0] != '\n') 
//         {
//             printf("Line %d: %s\n", line_count + 1, line);
// 			cntl = ft_parse_file(fd, data, line);
//             line_count++;
//         }
// 		free(line);
// 		line = get_next_line(fd);
// 	}

//     printf("Total lines in the file: %d\n", line_count);
	
//     // Check for additional conditions
//     close(fd);
// 	return (cntl);
// }

int	ft_rgb_texture(char **color)
{
	int i;
	
	i = -1;
	while (color[++i] != NULL)
	{
		if (ft_atoi(color[i]) < 0 || ft_atoi(color[i]) > 255)
		{
			printf("Error: Invalid color format of RGB\n");
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
		printf("Error: Invalid color format of RGB\n");
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
	free(*color);
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
	free(*texture);
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
	printf("Error: texture dosent exist\n");
	return (0);
}

int	ft_texture_init(t_data *data, int **cntl_texture, char *line, int i)
{
	int	ctrl;

	ctrl = 1;
	if ((*cntl_texture)[i] == 0)
	{
		(*cntl_texture)[i] = 1;
		if (i == 0)
			ctrl = ft_texture_path(&data->texture->NO, line);
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
		exit_error("Error: Extra texture parameter.");
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
			printf("Error: Texture parameter missing\n");
			return (0);
		}
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
	(void)cntl_map;

	ctrl = 1;
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
		ctrl = 0;
	return (ctrl);
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

int	ft_parse_file(int fd, t_data *data, char *line)
{
	int	cntl;
	int	i;
	int cntl_map;
	int cntl_texture[6];
	
	cntl = 1;
	i = -1;
	cntl_map = 0;
	while (++i < 6)
		cntl_texture[i] = 0;
	while (line && cntl == 1)
	{
		cntl = ft_map_texture(line, data, cntl_texture, &cntl_map);
		if (cntl_map == 1 && cntl == 1)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	line = ft_parse_text(fd, data, line, cntl);
	free(line);
	if (cntl == 1)
		cntl = ft_parse_map(fd, data);
	return (cntl);
}

int	ft_read_file(t_data *data)
{
	int fd;
    char *line;
	int cntl;

	if (open(data->map_path, O_RDONLY) > 0)
	{
		cntl = 1;
    	fd = open(data->map_path, O_RDONLY);
		line = get_next_line(fd);
		if (line == NULL)
		{
			exit_error("Map is empty.");
		}
		cntl = ft_parse_file(fd, data, line);
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

int main(int argc, char **argv)
{
    t_data data;

	if (argc != 2)
	{
		exit_error("Wrong number of arguments");
	}

	ft_bzero(&data, sizeof(t_data));
	ft_check_name(argv[1], &data);
	data.map = malloc(sizeof(t_map));
	data.texture = malloc(sizeof(t_texture));
	if (!data.map || !data.texture)
		return (0);
    ft_map_init(data.map);
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
