/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:43:08 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/19 19:12:50 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// void	ft_void(void)
// {
// 	system("leaks -q 'minishell'");
// }

// 	atexit(ft_void);

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void) argc;
	(void) argv;
	set_signal();
	ft_bzero(&data, sizeof(t_data));
	ft_init(&data, env);
	ft_minishell(&data);
	clear_history();
	return (0);
}
