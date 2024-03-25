/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/23 15:27:33 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	ft_collision(t_data *data, int x, int y)
{
	int	res;

	res = 0;
	if (data->map->matrix[y][x] != '0')
		res = 1;
	return (res);
}

float	ft_normalized(float angle)
{
	float	two_pi;
	float	normalized_angle;

	two_pi = 2 * M_PI;
	normalized_angle = fmod(angle, two_pi);
	if (normalized_angle < 0)
		normalized_angle += two_pi;
	return (normalized_angle);
}

t_point	ft_get_pos(t_point *pos, float angle, int n)
{
	t_point	new;

	new.x = pos->x + round(n * cos(angle) * P_SPEED);
	new.y = pos->y + round(n * sin(angle) * P_SPEED);
	return (new);
}

float	ft_pitagoras(float a, float b, float c, float d)
{
	float	n_pow_x;
	float	n_pow_y;
	float	n_sqr;

	n_pow_x = pow(a - b, 2);
	n_pow_y = pow(c - d, 2);
	n_sqr = sqrt(n_pow_x + n_pow_y);
	return (n_sqr);
}
