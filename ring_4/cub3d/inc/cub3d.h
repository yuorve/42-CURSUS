/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:19:43 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/26 18:08:53 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/inc/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <memory.h>

# define S_W 800
# define S_H 600
# define TILE_SIZE 30
# define FOV 1.0472
# define R_SPEED 0.05
# define P_SPEED 3
# define TEXTURE 64

# define N 90
# define S 270
# define E 180
# define W 0

typedef struct s_pos
{
	int	y;
	int	x;
}	t_pos;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**matrix;
	char	*file;
	int		ply_x;
	int		ply_y;
	int		width;
	int		height;
	int		n_player;
	char	direction;
	t_pos	player;
}	t_map;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_structure
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		c;
	int		f;
	int		count_params;
	int		cntl_map;
	char	**map;
	char	**copy_map;
	int		size_y;
	int		size_x;
	int		full_size;
}	t_structure;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_line;

typedef struct s_player
{
	mlx_image_t	*img;
	t_point		*pos;
	double		angle;
	int			forward;
	int			sidle;
	int			turn;
	int			mouse_turn;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_wall
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}	t_wall;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*tex;
	t_wall			*wall;
	t_ray			*ray;
	char			*map_path;
	int				map_fd;
	float			player_dir;
	t_map			*map;
	t_player		*ply;
	int				key;
	double			horiz_x;
	double			horiz_y;
	double			vert_x;
	double			vert_y;
	double			wall_h;
	t_structure		*structure;
	uint32_t		*pixels;
}	t_data;

// Parsing
void	read_map(t_data *data);

// Utils
int		ft_get_rgba(int r, int g, int b, int a);
int		ft_collision(t_data *data, int x, int y);
float	ft_normalized(float angle);
float	ft_pitagoras(float a, float b, float c, float d);
t_point	ft_get_pos(t_point *pos, float angle, int n);

// Key
void	ft_keys_press(mlx_key_data_t keydata, void *param);
void	ft_keys_release(mlx_key_data_t keydata, void *param);
// Minimap
void	ft_minimap(void *param);

// Drawing tools
void	ft_draw_line(t_point start, t_point end, mlx_image_t *img);
void	ft_draw_line_red(t_point start, t_point end, mlx_image_t *img);
void	ft_squar(t_point start, t_point end, mlx_image_t *img, uint32_t color);

// Player
void	ft_player(t_data *data);
void	ft_player_init(t_data *data);
void	ft_player_move(t_data *data, char *direction);
int		ft_player_collision(t_data *data, int x, int y);

// Cast
int		ft_circle(float angle, char c);
int		ft_inter_check(float angle, float *inter, float *step, int is_horizon);
int		ft_wall_hit(float x, float y, t_data *data);
void	ft_cast_rays(t_data *data);

// Render
void	ft_render(t_data *data, int ray);
void	ft_pixel_put(t_data *data, int x, int y, int color);

// Textures
int		ft_get_color(int pixel);
void	ft_load_texture(t_data *data);
void	ft_floor_ceiling(t_data *data, int ray, int t_pix, int b_pix);
// Free
void	ft_free_texture(t_data *data);
void	ft_free(t_data *data);

//cub3d.c
void	ft_game(void *param);
void	ft_move(mlx_t *mlx, t_data *data);
void	ft_keys_hook(mlx_key_data_t keydata, void *param);
void	ft_mouse_hook(double xdelta, double ydelta, void *param);

//main.c
void	ft_check_file(t_data *data);
void	ft_check_name(char *name, t_data *data);

//free.c
void	exit_error(const char *message);
void	ft_free_matrix(char **str);
void	ft_free_struct(t_data *data);
void	ft_free_structure(t_structure *structure);

//init.c
void	ft_init(t_data *data);
void	ft_map_init(t_map *map);
void	ft_structure_init(t_structure *structure);

//file_check.c
void	ft_structure_check(t_data *data);
void	ft_check_map_lines(t_data *data);
void	ft_check_empty_line_map(t_data *data, char *line);
int		ft_empty_line(char *line);

//map_check.c
int		ft_map_param(char *line);
void	ft_check_map(t_data *data);
void	ft_get_map_size(t_data *data);
void	ft_validate_map(t_data *data);

//parse_map.c
void	ft_flood_fill(t_data *data, int y, int x);
void	ft_check_flood(t_data *data);
void	ft_parsing_map(t_data *data);
void	ft_copy_map(t_data *data);

//player.c
void	ft_get_player(t_data *data, int y, int x);
void	ft_check_map_params(t_data *data);
void	ft_get_player_dir(t_data *data);
void	ft_check_player_pos(t_data *data, int y, int x);

//color_check.c
void	ft_validate_color(char	*c);
size_t	ft_split_size(char **split);
void	ft_free_split(char **split);
int		ft_check_color(char *str);

//param_check.c
char	*ft_param_path(char *path);
void	ft_get_param(t_data *data, char **param);
void	ft_param_exists(t_data *data, char *param);
void	ft_not_param(char *line, t_data *data);
int		ft_is_param(char *line);

//utils2.c
int		ft_get_len(char **array);
void	ft_process_texture(t_data *data, char **param, char **texture);
void	ft_process_color(t_data *data, char **param, int *color);
void	ft_check_texture_exists(char *texture);
void	ft_check_color_exists(int color);

#endif
