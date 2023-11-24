/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:23:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/24 21:02:56 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/inc/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

typedef struct	s_cmd
{
	char	**env_copy;
	char	*var_name;
	char	*var_value;
	//char	*path;
	char	**cmd_splited;
	char	**cmd_complete;
}	t_cmd;

typedef struct	s_data
{
	char	*input;
	int		npipes;
	int		num_command;
	t_list	*command;
	t_list	*parameter;
	t_cmd	*cmd;
}	t_data;


//minishell.c
void    set_signal(void);
void    handle_process_on(int sig);
void    handle_ctrl_c(int sig);

//init.c
void    ft_init(t_data *data, char **env);
void    ft_init(t_data *data, char **env);
void    ft_init_command(t_data *data);

//builtins.c
int ft_not_redirected_builtins(t_data *data);
//int ft_is_redirected_builtins(t_data *data);
int ft_execute_not_rebuiltins(t_data *data);
//int ft_execute_rebuiltins(t_data *data);
int ft_pwd(void);
int ft_exit(void);
int ft_env(t_data *data);
// int ft_export(t_data *data);
// int ft_unset(t_data *data);
// int ft_echo(t_data *data);
// int ft_cd(t_data *data);


//executer.c
char    *ft_get_path(char **cmd, t_data *data);
void    ft_devide_command(t_data *data);
void    ft_execute(t_data *data);


//free.c
void ft_free_matrix(char **array);

#endif