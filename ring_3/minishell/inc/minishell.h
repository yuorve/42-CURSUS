/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:23:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/29 19:03:55 by angalsty         ###   ########.fr       */
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

typedef struct	s_cmd
{
	char	**env_copy;
	char	*var_name;
	char	*var_value;
	//char	*path;
	char	**cmd_splited;
	char	**cmd_complete;
}	t_cmd;

typedef struct s_data
{
	char	*input;
	int		npipes;
	int		num_command;
	t_list	*command;
	t_list	*parameter;
	t_cmd	*cmd;
}	t_data;


//minishell.c
void	ft_minishell(t_data *data);
int		ft_checks(char c1, char c2);
void	ft_free_split(char **str);
void 	debug(t_data *data);
t_list	*ft_add_to_list(t_list *list, char *content);
int		ft_findpos(char *str, char c);
int		ft_quoted(char *str);
void	ft_spaces(t_data *data, char *str);
void	ft_pipes(t_data *data, char *str);
void	ft_input_checks(t_data *data, char *str);
void	ft_free(void *data);


//signals.c
void    set_signal(void);
void    handle_process_on(int sig);
void    handle_ctrl_c(int sig);

//init.c
void    ft_init(t_data *data, char **env);
void    ft_init(t_data *data, char **env);
void    ft_init_command(t_data *data);
void    ft_shell_level(t_data *data);

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
