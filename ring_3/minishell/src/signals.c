/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:06 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 21:38:02 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_ctrl_c(int sig)
{
	(void)sig;
	rl_on_new_line();
	ft_putstr_fd("\n", 0);
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_process_on(int sig)
{
	(void)sig;
	printf("I'm alive\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	set_signal(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGUSR2, handle_process_on);
	tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}

void	ft_control_d(t_data *i)
{
	(void)i;
	rl_on_new_line();
	ft_putstr_fd("exit\n", 0);
	exit(0);
}
