/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:01:13 by yoropeza          #+#    #+#             */
/*   Updated: 2023/03/28 19:45:31 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
		error_and_exit("usage: ./fdf <filename.fdf>");
	read_file(argv[1], &fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FdF");
	init_camera(&fdf);
	draw_lines(&fdf);
	mlx_key_hook(fdf.win_ptr, handle_key, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0, handle_exit, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
