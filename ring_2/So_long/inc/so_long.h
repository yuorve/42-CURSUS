/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:19:05 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/07 19:43:50 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/inc/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*ground;
	mlx_image_t	*wall;
	mlx_image_t	*iplayer;
	mlx_image_t	*exit_open;
	mlx_image_t	*exit_close;
	mlx_image_t	*ikeys;
	char		**map;
	char		*file;
	size_t		map_width;
	size_t		map_height;
	int			player;
	int			keys;
	int			steps;
	int			points;
	int			exit;
	int			isize;
	t_point		player_pos;
	t_point		exit_pos;
}	t_data;

void	quit(char *err);
void	reading(t_data *data);
void	flood_fill(char **matrix, t_point start);
void	ft_freeplus(char **matrix, int size);
void	drawing(t_data *data);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	moves(t_data *data, int x, int y);

int		thisistheway(char **matrix, t_point start);

char	**ft_copy(char **matrix, int size);
#endif
