/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:08:13 by yoropeza          #+#    #+#             */
/*   Updated: 2023/03/28 18:19:01 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define BUFFER_SIZE 128

typedef struct	s_point
{
  double	x;
  double	y;
  double	z;
  int		color;
}		t_point;

typedef struct	s_line
{
  t_point	start;
  t_point	end;
}		t_line;

typedef struct	s_camera
{
  int		zoom;
  double	alpha;
  double	beta;
  double	gamma;
  int		x_offset;
  int		y_offset;
  int		z_offset;
}		t_camera;

typedef struct	s_image
{
  void		*img_ptr;
  int		width;
  int		height;
}		t_image;

typedef struct	s_fdf
{
  t_camera	camera;
  t_point	**map;
  int		width;
  int		height;
  void		*mlx_ptr;
  void		*win_ptr;
  t_image	image;
}		t_fdf;

void	draw_line(t_fdf *fdf, t_line line);
void	draw_map(t_fdf *fdf);
void	draw_image(t_fdf *fdf);
void	init_camera(t_fdf *fdf);
void	init_fdf(t_fdf *fdf, char *filename);
void	read_file(t_fdf *fdf, char *filename);
int		get_color(char *str);
void	put_pixel(t_fdf *fdf, int x, int y, int color);
void	put_line(t_fdf *fdf, t_point start, t_point end, int color);
void	rotate_x(double *y, double *z, double alpha);
void	rotate_y(double *x, double *z, double beta);
void	rotate_z(double *x, double *y, double gamma);
void	rotate(t_fdf *fdf, double *x, double *y, double *z);
void	project(t_fdf *fdf, double *x, double *y, double *z);
int		handle_key(int key, t_fdf *fdf);
void	handle_errors(int error);
void	free_map(t_fdf *fdf);

#endif