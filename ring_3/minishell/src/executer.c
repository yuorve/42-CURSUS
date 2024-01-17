/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/17 21:45:43 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_execute_child(t_data *data, t_list *head, int prev_pipe)
{
	signal(SIGUSR2, handle_process_on);
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (head->next != NULL && !(data->nredirection == 2 && data->redirection == '<'))
	{
		dup2(data->cmd->pipefd[1], STDOUT_FILENO);
	}
	close(data->cmd->pipefd[0]);
	close(data->cmd->pipefd[1]);
	ft_redirections(data);
	if (data->cmd->path != NULL)
		execve(data->cmd->path, data->cmd->cmd_splited, data->cmd->env_copy);
}

void	ft_execute_parent(int status, t_data *data, t_list *head, int prev_pipe)
{
	signal(SIGUSR2, SIG_IGN);
	rl_set_prompt("");
	if (prev_pipe != -1)
	{
		close(prev_pipe);
	}
	if (head->next != NULL)
	{
		close(data->cmd->pipefd[1]);
	}
	if (head->next == NULL)
	{
		close(data->cmd->pipefd[0]);
	}
	// if (head->next == NULL)
	// {
	// 	waitpid(data->cmd->pid, &status, 0);
	// 	if (WIFEXITED(status))
	// 	{
	// 		data->cmd->exit_status = WEXITSTATUS(status);
	// 	}
	// }
	waitpid(data->cmd->pid, &status, 0);
	if (WIFEXITED(status))
	{
		data->cmd->exit_status = WEXITSTATUS(status);
	}
}

int	ft_error_infile(t_data *data)
{
	if (data->cmd->path != NULL && (data->nredirection == 1 && data->redirection == '<'))
	{
		if (access(ft_filename(data, data->file), F_OK) != 0)
		{
			printf("minishell: %s: No such file or directory\n", data->file);
			data->cmd->exit_status = 1;
			free(data->cmd->path);
			ft_free_matrix(data->cmd->cmd_splited);
			free(data->file);
			return (1);
		}
	}
	return (0);
}

void	ft_execute_pipes(t_data *data, t_list *head)
{
	int	prev_pipe;

	prev_pipe = -1;
	signal(SIGUSR2, SIG_IGN);
	while (head)
	{
		ft_input_checks(data, head->content);
		if (ft_not_redirected_builtins(data) == 1 && head->next != NULL)
			head = head->next;
		ft_get_command(head, data);
		data->cmd->cmd_splited = ft_command(head->content, data);
		data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
		if (data->cmd->path == NULL && ft_redirection_check(data) == 0)
			return (ft_free_execute(data));
		if (ft_error_infile(data) == 1)
			return ;
		ft_execute_command(data, head, prev_pipe);
		if ((access(*data->cmd->cmd_splited, 0) != 0))
			free(data->cmd->path);
		ft_restart(data);
		prev_pipe = data->cmd->pipefd[0];
		head = head->next;
	}
}

void	ft_execute(t_data *data)
{
	t_list	*head;

	head = data->command;
	if (ft_is_redirected_builtins(data) == 1 && head->next == NULL)
	{
		ft_params(data, data->command->content);
		ft_execute_rebuiltins(data);
	}
	else if (ft_not_redirected_builtins(data) == 1 && head->next == NULL)
	{
		ft_params(data, data->command->content);
		ft_execute_not_rebuiltins(data);
	}
	else
		ft_execute_pipes(data, head);
}
