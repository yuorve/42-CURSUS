/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:19:05 by yoropeza          #+#    #+#             */
/*   Updated: 2023/10/25 17:07:37 by yoropeza         ###   ########.fr       */
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
}   t_point;

typedef struct s_data
{
	mlx_t	*mlx;
	char	**map;
	int		map_width;
	int		map_heigth;
	int		keys;
	int		points;
}   t_data;

#endif
