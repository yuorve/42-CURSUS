/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 19:59:06 by angalsty          #+#    #+#             */
/*   Updated: 2023/12/11 21:21:34 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

struct termios	t;

void    handle_ctrl_c(int sig)
{
    (void)sig;
    
    // //rl_replace_line("", 0); //clears the line
    // rl_on_new_line(); //moves the cursor to the beginning of the line and writes Minishell
    // //rl_redisplay();
    // kill(0, SIGUSR2); //sends a signal to the process
    
    // ft_putstr_fd("\n", 0); //writes a new line
    // rl_on_new_line(); //moves the cursor to the beginning of the line and writes Minishell
    // //rl_replace_line("", 0); //clears the line
    // rl_redisplay(); //writes minishell on the desktop

    rl_on_new_line(); //moves the cursor to the beginning of the line and writes Minishell
    ft_putstr_fd("\n", 0); //writes a new line
    rl_replace_line("", 0); //Reemplaza la línea actualmente ingresada con otra proporcionada.
    rl_redisplay(); //Vuelve a mostrar la línea actualmente ingresada.
}

void    handle_process_on(int sig)
{
    (void)sig;
    //rl_replace_line("", 0); //clears the line
    //rl_on_new_line(); //moves the cursor to the beginning of the line and writes Minishell
    rl_redisplay(); //writes minishell on the desktop
    //rl_set_prompt("");
}

void    set_signal(void)
{
    signal(SIGINT, handle_ctrl_c);
    signal(SIGQUIT, SIG_IGN); //ignores the signal
    signal(SIGUSR2, handle_process_on);
    tcgetattr(0, &t);
	t.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
    signal(SIGTSTP, SIG_IGN);
}