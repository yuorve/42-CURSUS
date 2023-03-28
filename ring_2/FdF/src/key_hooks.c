/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:12:26 by yoropeza          #+#    #+#             */
/*   Updated: 2023/03/28 19:12:36 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		free_fdf(fdf);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		handle_zoom(keycode, fdf);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT
		|| keycode == KEY_DOWN || keycode == KEY_UP)
		handle_move(keycode, fdf);
	else if (keycode == KEY_R || keycode == KEY_G || keycode == KEY_B)
		handle_color(keycode, fdf);
	else if (keycode == KEY_ISO || keycode == KEY_PARA)
		handle_projection(keycode, fdf);
	return (0);
}

void	handle_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
		fdf->camera->zoom++;
	else if (keycode == KEY_MINUS && fdf->camera->zoom > 1)
		fdf->camera->zoom--;
	draw_image(fdf);
}

void	handle_move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_LEFT)
		fdf->camera->offset_x -= MOVE_STEP;
	else if (keycode == KEY_RIGHT)
		fdf->camera->offset_x += MOVE_STEP;
	else if (keycode == KEY_DOWN)
		fdf->camera->offset_y += MOVE_STEP;
	else if (keycode == KEY_UP)
		fdf->camera->offset_y -= MOVE_STEP;
	draw_image(fdf);
}

void	handle_color(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_R)
		fdf->color = RED;
	else if (keycode == KEY_G)
		fdf->color = GREEN;
	else if (keycode == KEY_B)
		fdf->color = BLUE;
	draw_image(fdf);
}

void	handle_projection(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ISO)
		fdf->camera->projection = ISO;
	else if (keycode == KEY_PARA)
		fdf->camera->projection = PARA;
	draw_image(fdf);
}
