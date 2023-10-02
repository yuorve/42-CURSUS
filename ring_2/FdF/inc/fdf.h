/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:38:34 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/27 14:19:07 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#define WIDTH 512
#define HEIGHT 512

# include "../lib/libft/inc/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <limits.h>
# include <math.h>

// Estructura de un punto en el mapa
typedef struct s_Point3D
{
	int		x;
	int 	y;
	int 	z;
	struct	s_Point3D	*next;
}			t_Point3D;

// Estructura de un punto en el mapa
typedef struct s_Point2D
{
	double	x;
	double	y;
	struct	s_Point2D	*next;
}			t_Point2D;

// Estructura de una línea en el mapa
typedef struct s_Line
{
	struct	s_Point2D	*start;
	struct	s_Point2D	*end;
}			t_Line;

// Estructura del mapa
typedef struct s_Map
{
	int					size;
	struct	s_Point2D	*start;
}			t_Map;

// Estructura del conjunto de datos
typedef struct	s_Data
{
		t_Map	*map;
}				t_Data;

#endif
