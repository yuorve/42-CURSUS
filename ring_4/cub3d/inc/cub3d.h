/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:19:43 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/05 20:46:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft/inc/libft.h"
#include "../lib/MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <memory.h>

typedef struct s_point {
    int	x;
    int	y;
}	t_point;

typedef struct s_tile {
    size_t	height;
    size_t	width;
}	t_tile;

typedef struct s_map {
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_line {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
}	t_line;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**matrix;
	char		*mapfile;
	size_t		map_width;
	size_t		map_height;
	size_t		tile_width;
	size_t		tile_height;
	int			matrix_height;
	int			matrix_width;
	int			key;
	mlx_image_t	*player;
	int			player_x;
	int			player_y;
	int			forward;
	int			sidle;
	int			turn;
	float		anglerotation;
	int			speed_move;
	float		speed_turn;
}	t_data;

int		ft_get_rgba(int r, int g, int b, int a);
int		ft_collision(t_data *data, int x, int y);
float	ft_normalized(float angle);
void	read_map(t_data *data);
t_point	ft_get_tile(t_data *data, int x, int y);
// Key utils
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
void	ft_cast(t_data *data, int x, int y, float angle, int col);
