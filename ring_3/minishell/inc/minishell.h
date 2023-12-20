/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:23:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/12/20 21:53:56 by angalsty         ###   ########.fr       */
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
# include <errno.h>
#define READ_END 0
#define WRITE_END 1

typedef struct s_env_node 
{
    char *name;
    char *value;
	int	 equal;
    struct s_env_node *next;
} t_env_node;

typedef struct	s_cmd
{
	char	*command;
	char	*param;
	char	**env_copy;
	char	*path;
	char	**cmd_splited;
	int		pipefd[2];
	int		outfiles;
	int		infiles;
	int 	append;
	int 	heredoc;
	//int 	pid;
	//char	**cmd_complete;
}	t_cmd;

typedef struct s_data
{
	char	**env;
	char	*input;
	char	*file;
	char	redirection;
	int		nredirection;
	int		npipes;
	int		num_command;
	t_list	*command;
	t_list	*parameter;
	t_cmd	*cmd;
	t_env_node  *env_list;
}	t_data;


//minishell.c
void	ft_minishell(t_data *data);
int		ft_checks(char c1, char c2);
void	ft_free_split(char **str);
void 	debug(t_data *data);
t_list	*ft_add_to_list(t_list *list, char *content);
int		ft_findpos(char *str, char c);
int		ft_quoted(char *str);
void	ft_pipes(t_data *data, char *str);
void	ft_input_checks(t_data *data, char *str);
void	ft_free(void *data);
void	ft_params(t_data *data, char *str);
char    **ft_command(char *str, t_data *data);


//signals.c
void    set_signal(void);
void    handle_process_on(int sig);
void    handle_ctrl_c(int sig);
void 	ft_control_d(t_data *i);

//init.c
void    ft_init(t_data *data, char **env);
void    ft_init_command(t_data *data);
//void    ft_shell_level(t_data *data);
void 	ft_init_env(t_env_node **head, char **env);
//void	ft_push_env_node(t_env_node **head, char *name, char *value);
void ft_push_env_node(t_env_node **head, char *name, char *value, int equal);
//t_env_node *ft_create_env_node(char *name, char *value);
t_env_node *ft_create_env_node(char *name, char *value, int equal);
t_env_node	*ft_listlast(t_env_node *lst);
void 	ft_shell_level(t_env_node **head, int i);
t_env_node *ft_find_node(t_env_node *head, const char *name);
int		ft_count_nodes(t_env_node *head);


//builtins.c
int 	ft_not_redirected_builtins(t_data *data);
//int 	ft_is_redirected_builtins(t_data *data);
int 	ft_execute_not_rebuiltins(t_data *data);
//int 	ft_execute_rebuiltins(t_data *data);
int 	ft_pwd(void);
int 	ft_exit(t_data *data);
int 	ft_env(t_data *data);
void 	ft_swap_values(char *str1, char *str2);
void 	ft_sort_env_list(t_env_node **head);
void 	ft_print_sorted_env(t_env_node *head);
int 	ft_export(t_data *data);
int 	ft_unset(t_data *data);
int 	ft_echo(t_data *data);
int 	ft_cd(t_data *data);


//executer.c
char 	*join_path(char *path, char *cmd);
char 	*check_path(char **path, char *cmd);
char 	*find_command_path(char **env_copy, char *cmd);
char    *ft_get_path(char **cmd, t_data *data);
//char	*ft_cmd(t_data *data, char *cmd);
void    ft_execute_child(t_data *data, t_list *head, int prev_pipe);
void    ft_execute_parent(int status, t_data *data, t_list *head, int prev_pipe, int pid);
void 	ft_execute_pipes(t_data *data, t_list *head);
void    ft_execute(t_data *data);
int	ft_redirections_pars(t_data *data);
void	ft_redirections(t_data *data);
void	ft_dup_infile(t_data *data);
void	ft_dup_outfile(t_data *data);

//utils.c
int 	ft_strcmp(const char *str1, const char *str2);

//free.c
void 	ft_free_matrix(char **array);

#endif
