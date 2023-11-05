/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:27:14 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/05 15:54:16 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	quit(t_data *data, char *err)
{
	(void) data;
	ft_printf("%s\n", err);
	exit(EXIT_FAILURE);
}

void	ft_freeplus(char **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

char	**ft_copy(char **matrix, int size)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * size);
	if (new == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = ft_strdup(matrix[i]);
		i++;
	}
	return (new);
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
		data.file = ft_strjoin("resources/", argv[1]);
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4))
			quit(&data, "Error file name");
		data.isize = 64;
		reading(&data);
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
