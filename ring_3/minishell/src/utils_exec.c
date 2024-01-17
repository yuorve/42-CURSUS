/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:10:21 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/17 21:58:55 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_execute_command(t_data *data, t_list *head, int prev_pipe)
{
	int	status;

	status = 0;
	if (pipe(data->cmd->pipefd) == -1)
		ft_perror();
	data->cmd->pid = fork();
	if (data->cmd->pid == -1)
		ft_perror();
	else if (data->cmd->pid == 0)
		ft_execute_child(data, head, prev_pipe);
	else
		ft_execute_parent(status, data, head, prev_pipe);
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
	ft_free_matrix(command);
}

char	*ft_filename(t_data *data, char *str)
{
	t_env_node	*tmp;
	char		*leak;
	char		*name;

	if (ft_strchr(str, '$'))
	{
		leak = ft_variable(str);
		tmp = ft_find_node(data->env_list, leak);
		if (tmp)
		{
			name = tmp->value;
			return (free(leak), name);
		}
		else
			return (free(leak), str);
	}
	else
		return (str);
}
