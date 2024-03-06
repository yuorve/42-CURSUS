/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:19:43 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/28 20:25:21 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/inc/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <memory.h>

#define S_W 800
#define S_H 600
#define TILE_SIZE 30
#define FOV 1.0472
#define R_SPEED 0.05
#define P_SPEED 3
#define TEXTURE 64

typedef struct s_line
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_line;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_player
{
	mlx_image_t	*img;
	t_point		*pos;
	double		angle;
	int			forward;
	int			sidle;
	int			turn;
}	t_player;

typedef struct s_ray
{
	double	angle;
	double	distance;
	int		flag;
}	t_ray;

typedef struct s_map
{
	char	**matrix;
	char	*file;
	int		ply_x;
	int		ply_y;
	int		width;
	int		height;
}	t_map;

typedef struct s_wall
{
	mlx_image_t	*north;
	mlx_image_t	*south;
	mlx_image_t	*east;
	mlx_image_t	*west;
}	t_wall;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*png;
	t_wall			*wall;
	t_ray			*ray;
	t_map			*map;
	t_player		*ply;
	int				key;
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
// Drawing tools
void	ft_draw_scene(t_data *data);
void	ft_draw_line(t_point start, t_point end, mlx_image_t *img);
void	ft_draw_line_red(t_point start, t_point end, mlx_image_t *img);
void	ft_draw_square(t_point start, t_point end, mlx_image_t *img);
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
// Textures
int		ft_get_color(mlx_image_t *img, int pixel);
void	ft_load_texture(t_data *data);
