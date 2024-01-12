/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:37:28 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/12 18:55:53 by angalsty         ###   ########.fr       */
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

void	ft_exit_num_error(t_data *data)
{
	printf("minishell: exit:");
	printf(" %s: numeric argument required\n", data->parameter->content);
	data->cmd->exit_status = 255;
	exit (255);
}
