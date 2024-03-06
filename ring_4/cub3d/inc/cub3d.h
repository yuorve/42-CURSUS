/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:19:43 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/04 21:30:03 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "../lib/libft/inc/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <memory.h>


#define N 0;
#define S 180;
#define E 90;
#define W 270;

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct s_map
{
	int n_rows;
	int n_lines;
	int n_player;
	char direction;
	t_pos player;
}	t_map;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_structure
{
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	int  C;
	int  F;
	//char **C;
	// char **F;
	int	count_params;
	int cntl_map;
	char **map;
	char **copy_map;
	int size_y;
	int size_x;
	int full_size;
}	t_structure;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	//char		**map;
	char		*map_path;
	int			map_fd;
	char		*mapfile;
	size_t		map_width;
	size_t		map_height;
	float		player_dir;
	int			key;
	t_map		*map;
	t_structure	*structure;
}	t_data;


//main.c
void	ft_print_map(t_data *data);
int		ft_get_len(char **array);
void	ft_check_file(t_data *data);
void   	ft_check_name(char *name, t_data *data);

//free.c
void	exit_error(const char *message);
void 	ft_free_matrix(char **str);
void	ft_free_struct(t_data *data);
void	ft_free_structure(t_structure *structure);
//void	ft_free_map(t_map *map);

//init.c
void	ft_map_init(t_map *map);
void	ft_structure_init(t_structure *structure);

//file_check.c
void	ft_structure_check(t_data *data);
void 	ft_check_map_lines(t_data *data);
void 	ft_check_empty_line_map(t_data *data, char *line);
int		ft_empty_line(char *line);

//map_check.c
int		ft_map_param(char *line);
void	ft_check_map(t_data *data);
void	ft_get_map_size(t_data *data);
void	ft_validate_map(t_data *data);

//parse_map.c
void 	ft_flood_fill(t_data *data, int y, int x);
void	ft_check_flood(t_data *data);
void	ft_parsing_map(t_data *data);
void 	ft_copy_map(t_data *data);

//player.c
void	ft_check_map_params(t_data *data);
void	ft_get_player_dir(t_data *data);
void	ft_check_player_pos(t_data *data, int y, int x);

//color_check.c
void	validate_color(char	*c);
size_t	split_size(char **split);
void	free_split(char **split);
int		ft_get_color(char *str);

//param_check.c
void	ft_param_path(char *path);
void 	ft_get_param(t_data *data, char **param);
void	ft_param_exists(t_data *data, char *param);
void	ft_not_param(char *line, t_data *data);
int		ft_is_param(char *line);


#endif