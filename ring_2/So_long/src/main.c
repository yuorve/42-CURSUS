/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:14 by yoropeza          #+#    #+#             */
/*   Updated: 2023/10/30 13:17:03 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	quit(t_data *data, char *err)
{
	free(data->map);
	free(data);
	ft_printf(err, %s);
	exit(EXIT_FAILURE);
}

int32_t	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc == 2)
	{
		ft_bzero(&data, sizeof(t_data));
		reading(data, argv[1]);
	}
	else if (argc < 2)
		ft_printf("\e[31mError\nMissing arguments\e[0m\n");
	else if (argc > 2)
		ft_printf("\e[31mError\nToo many arguments\e[0m\n");
	return (EXIT_SUCCESS);
}
