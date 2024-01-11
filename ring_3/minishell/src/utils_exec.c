/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:10:21 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 21:52:36 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_execute_command(t_data *data, t_list *head, int prev_pipe)
{
	int	pid;
	int	status;

	status = 0;
	if (pipe(data->cmd->pipefd) == -1)
		ft_perror();
	pid = fork();
	if (pid == -1)
		ft_perror();
	else if (pid == 0)
		ft_execute_child(data, head, prev_pipe);
	else
		ft_execute_parent(status, data, head, prev_pipe, pid);
}

void	ft_free_execute(t_data *data)
{
	printf("Error: command not found\n");
	data->cmd->exit_status = 127;
	ft_free_matrix(data->cmd->cmd_splited);
}

void	ft_restart(t_data *data)
{
	data->redirection = 0;
	ft_free_matrix(data->cmd->cmd_splited);
	free(data->file);
}

void	ft_get_command(t_list *head, t_data *data)
{
	char	**command;

	command = ft_split(head->content, data->redirection);
	free(head->content);
	head->content = ft_strtrim(command[0], " ");
	data->file = ft_strtrim(command[1], " ");
	//data->file = ft_filename(data, command[1]);
	ft_free_matrix(command);
}

char	*ft_filename(t_data *data, char *str)
{
	t_env_node	*tmp;
	char		*leak;

	if (ft_strchr(str, '$'))
	{
		leak = ft_variable(str);
		tmp = ft_find_node(data->env_list, leak);
		if (tmp)
			return (free (leak), tmp->value);
		else
			return (free (leak), ft_strtrim(str, " "));
	}
	else
		return (ft_strtrim(str, " "));
}
