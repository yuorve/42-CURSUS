/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:37:28 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 21:46:47 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_perror(void)
{
	perror("minishell");
	return ;
}

void	ft_exit_error(void)
{
	perror("fd_outfile:");
	exit(EXIT_FAILURE);
}

int	ft_error_path(void)
{
	printf("Error: path not found\n");
	return (0);
}
