/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:14 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/01 21:04:38 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	quit(t_data *data, char *err)
{
	//if (data->map != NULL)
	//	free(data->map);
	//if (data != NULL)
	//	free(data);
	(void) data;
	ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

void	ft_void(void)
{
	system("leaks -q 'so_long'");
}

int32_t	main(int argc, char **argv)
{
	t_data	data;

	atexit(ft_void);
	if (argc == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		reading(&data, argv[1]);
		data.isize = 64;
		drawing(&data);
		mlx_key_hook(data.mlx, &my_keyhook, &data);
		mlx_loop(data.mlx);
		mlx_terminate(data.mlx);
	}
	else if (argc < 2)
		ft_printf("\e[31mError\nMissing arguments\e[0m\n");
	else if (argc > 2)
		ft_printf("\e[31mError\nToo many arguments\e[0m\n");
	return (EXIT_SUCCESS);
}
