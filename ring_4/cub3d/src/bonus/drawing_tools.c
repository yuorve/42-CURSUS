/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:24:58 by yoropeza          #+#    #+#             */
/*   Updated: 2024/03/25 17:37:55 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_line	ft_get_line(t_point start, t_point end)
{
	t_line	line;

	ft_bzero(&line, sizeof(t_line));
	line.dx = abs(end.x - start.x);
	line.dy = abs(end.y - start.y);
	if (start.x < end.x)
		line.sx = 1;
	else
		line.sx = -1;
	if (start.y < end.y)
		line.sy = 1;
	else
		line.sy = -1;
	return (line);
}

void	ft_draw_line(t_point start, t_point end, mlx_image_t *img)
{
	int		e2;
	int		err;
	t_line	line;

	line = ft_get_line(start, end);
	err = line.dx - line.dy;
	while (1)
	{
		mlx_put_pixel(img, start.x, start.y, 0xFFFFFFFF);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 > -line.dy)
		{
			err -= line.dy;
			start.x += line.sx;
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			start.y += line.sy;
		}
	}
}

void	ft_draw_line_red(t_point start, t_point end, mlx_image_t *img)
{
	int		e2;
	int		err;
	t_line	line;

	line = ft_get_line(start, end);
	err = line.dx - line.dy;
	while (1)
	{
		mlx_put_pixel(img, start.x, start.y, 0xFF0000FF);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = 2 * err;
		if (e2 > -line.dy)
		{
			err -= line.dy;
			start.x += line.sx;
		}
		if (e2 < line.dx)
		{
			err += line.dx;
			start.y += line.sy;
		}
	}
}

void	ft_squar(t_point start, t_point end, mlx_image_t *img, uint32_t color)
{
	int	i;

	i = start.x;
	end.x += start.x;
	end.y += start.y;
	while (1)
	{
		mlx_put_pixel(img, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		else if (start.x == end.x)
		{
			start.y++;
			start.x = i;
		}
		else
			start.x++;
	}
}
