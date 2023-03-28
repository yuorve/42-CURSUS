/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:13:45 by yoropeza          #+#    #+#             */
/*   Updated: 2023/03/28 19:46:47 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_transformations(t_point *point, t_fdf *fdf)
{
	translate_point(point, fdf->camera->x_offset, fdf->camera->y_offset, 0);
	scale_point(point, fdf->camera->zoom, fdf->camera->zoom, fdf->camera->zoom);
	if (fdf->camera->projection == ISO)
		iso_point(point);
	rotate_x(&(point->y), &(point->z), fdf->camera->x_rotation);
	rotate_y(&(point->x), &(point->z), fdf->camera->y_rotation);
	rotate_z(&(point->x), &(point->y), fdf->camera->z_rotation);
}

void	translate_point(t_point *point, int x, int y, int z)
{
	point->x += x;
	point->y += y;
	point->z += z;
}

void	scale_point(t_point *point, float x, float y, float z)
{
	point->x *= x;
	point->y *= y;
	point->z *= z;
}

void	iso_point(t_point *point)
{
	int previous_x;
	int previous_y;

	previous_x = point->x;
	previous_y = point->y;
	point->x = (previous_x - previous_y) * cos(ISO_ANGLE);
	point->y = -point->z + (previous_x + previous_y) * sin(ISO_ANGLE);
}

void	rotate_x(int *y, int *z, double angle)
{
	int previous_y;
	int previous_z;

	previous_y = *y;
	previous_z = *z;
	*y = previous_y * cos(angle) + previous_z * sin(angle);
	*z = -previous_y * sin(angle) + previous_z * cos(angle);
}

void	rotate_y(int *x, int *z, double angle)
{
	int previous_x;
	int previous_z;

	previous_x = *x;
	previous_z = *z;
	*x = previous_x * cos(angle) + previous_z * sin(angle);
	*z = -previous_x * sin(angle) + previous_z * cos(angle);
}

void	rotate_z(int *x, int *y, double angle)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle) - previous_y * sin(angle);
	*y = previous_x * sin(angle) + previous_y * cos(angle);
}
