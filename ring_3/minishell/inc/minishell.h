/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:23:55 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/17 21:55:37 by angalsty         ###   ########.fr       */
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
# define READ_END 0
# define WRITE_END 1

typedef struct s_env_node
{
	char				*name;
	char				*value;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_cmd
{
	char	*command;
	char	*param;
	char	**env_copy;
	char	*path;
	char	**cmd_splited;
	int		pipefd[2];
	int		exit_status;
	int		outfiles;
	int		infiles;
	int		append;
	int		heredoc;
	int		pid;
}	t_cmd;

typedef struct s_data
{
	char		**env;
	char		*input;
	char		*file;
	char		redirection;
	int			nredirection;
	int			npipes;
	int			num_command;
	int			input_error;
	int			expand;
	t_list		*command;
	t_list		*parameter;
	t_cmd		*cmd;
	t_env_node	*env_list;
}	t_data;

typedef struct s_strxstr
{
	int		i;
	int		j;
	char	*start;
	char	*end;
	char	*res;
}	t_strxstr;

typedef struct s_params
{
	int			i;
	int			j;
	int			flag;
	char		*tmp;
	char		*leak;
	char		**values;
	t_env_node	*head;
}	t_params;

typedef struct s_replace
{
	int		i;
	int		j;
	int		flag;
}	t_replace;

//minishell.c
void		ft_minishell(t_data *data);
void		ft_pipes(t_data *data, char *str);
char		*ft_replace(char *str);

//params.c
char		**ft_command(char *str, t_data *data);
void		ft_params(t_data *data, char *str);

//list.c
t_list		*ft_previously(t_list *list, t_list *target);
t_list		*ft_add_to_list(t_list *list, char *content);
char		**ft_list_to_matrix(t_env_node *head);

//checks_utils.c
char		*ft_variable(char *str);
int			ft_checks(char c1, char c2);
int			ft_findpos(char *str, char c);
int			ft_quoted(char *str);
void		ft_checks_zeros(t_data *data, int *start, int *flag, int *i);

//checks.c
void		ft_input_checks(t_data *data, char *str);

//signals.c
void		set_signal(void);
void		handle_process_on(int sig);
void		handle_ctrl_c(int sig);
void		ft_control_d(t_data *i);

//init.c
void		ft_init(t_data *data, char **env);
void		ft_init_command(t_data *data);
void		ft_init_env(t_env_node **head, char **env);
void		ft_shell_level(t_env_node **head, int i);

//init_node.c
t_env_node	*ft_create_env_node(char *name, char *value);
t_env_node	*ft_listlast(t_env_node *lst);
t_env_node	*ft_find_node(t_env_node *head, const char *name);
int			ft_count_nodes(t_env_node *head);
void		ft_push_env_node(t_env_node **head, char *name, char *value);

//builtins.c
int			ft_not_redirected_builtins(t_data *data);
int			ft_is_redirected_builtins(t_data *data);
int			ft_execute_not_rebuiltins(t_data *data);
int			ft_execute_rebuiltins(t_data *data);

//builtins_2.c
int			ft_pwd(t_data *data);
int			ft_echo(t_data *data);
int			ft_is_numeric(const char *str);
int			ft_exit(t_data *data);
int			ft_env(t_data *data);

//utils_builtins.c
void		ft_swap_values(char **str1, char **str2);
void		ft_sort_env_list(t_env_node **head);
void		ft_free_node(t_env_node *node);
void		ft_print_sorted_env(t_env_node *head);
int			ft_command_not_found(t_data *data);

//unset.c
int			ft_check_parameter(t_data *data, char *param_content);
int			ft_check_and_remove(t_data *data, t_env_node **env_list,
				t_list *parameters);
int			ft_unset(t_data *data);

//export.c
int			ft_export(t_data *data);
char		ft_find_variable(t_data *data, t_list *tmp);
int			ft_exists_variable(t_data *data, char *param_content, char *value);
int			ft_check_export_errors(t_data *data);

//cd.c
void		ft_swap_dir(char *str1, char *str2);
char		*ft_cd_utils(t_data *data);
void		ft_update_pwd(t_data *data, char *var);
int			ft_cd(t_data *data);

//executer.c
void		ft_execute_child(t_data *data, t_list *head, int prev_pipe);
void		ft_execute_parent(int status, t_data *data, t_list *head,
				int prev_pipe);
void		ft_execute_pipes(t_data *data, t_list *head);
void		ft_execute(t_data *data);

//utils_exec.c
void		ft_execute_command(t_data *data, t_list *head, int prev_pipe);
void		ft_free_execute(t_data *data);
void		ft_restart(t_data *data);
char		*ft_filename(t_data *data, char *str);
void		ft_get_command(t_list *head, t_data *data);

//path.c
char		*ft_join_path(char *path, char *cmd);
char		*ft_check_path(char **path, char *cmd);
char		*ft_find_command_path(char **env_copy, char *cmd);
char		*ft_get_path(char **cmd, t_data *data);

//redirection.c
void		ft_redirections(t_data *data);
void		ft_dup_infile(t_data *data);
void		ft_dup_outfile(t_data *data);
void		ft_heredoc(t_data *data);
int			ft_redirection_check(t_data *data);

//utils.c
int			ft_strcmp(const char *str1, const char *str2);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strxstr(char *str, char *from, char *to);

//free.c
void		ft_free_matrix(char **array);
void		ft_free_split(char **str);
void		ft_free(void *data);
void		ft_free3(char *str1, char *str2, char *str3);
void		ft_free_minishell(t_data *data);

//error.c
void		ft_exit_error(void);
void		ft_perror(void);
int			ft_error_path(void);
void		ft_exit_num_error(t_data *data);

#endif
