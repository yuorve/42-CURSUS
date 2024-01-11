/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:12:01 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 21:45:29 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_execute_child(t_data *data, t_list *head, int prev_pipe)
{
	signal(SIGUSR2, handle_process_on);
	ft_redirections(data);
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (head->next != NULL)
	{
		dup2(data->cmd->pipefd[1], STDOUT_FILENO);
	}
	close(data->cmd->pipefd[0]);
	close(data->cmd->pipefd[1]);
	if (data->cmd->path != NULL)
		execve(data->cmd->path, data->cmd->cmd_splited, data->cmd->env_copy);
}

void	ft_execute_parent(int status, t_data *data, t_list *head, int prev_pipe, int pid)
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
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		data->cmd->exit_status = WEXITSTATUS(status);
	}
	// if (WIFEXITED(status))
	// {
	//     if (WEXITSTATUS(status) == 0)
	//     {
	//         printf("Command executed successfully\n");
	//     }
	//     else
	//     {
	//         printf("Command failed with code: %d\n", WEXITSTATUS(status));
	//     }
	// }
}

void	ft_execute_pipes(t_data *data, t_list *head)
{
	int	prev_pipe;

	prev_pipe = -1;
	signal(SIGUSR2, SIG_IGN);
	while (head)
	{
		if (ft_not_redirected_builtins(data) == 1 && head->next != NULL)
			head = head->next;
		ft_get_command(head, data);
		data->cmd->cmd_splited = ft_command(head->content, data);
		data->cmd->path = ft_get_path(data->cmd->cmd_splited, data);
		if (data->cmd->path == NULL && ft_redirection_check(data) == 0)
		{
			ft_free_execute(data);
			return ;
		}
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
		printf("Is redirected builtins, will not enter en execute\n");
		ft_execute_rebuiltins(data);
	}
	else if (ft_not_redirected_builtins(data) == 1 && head->next == NULL)
	{
		ft_execute_not_rebuiltins(data);
	}
	else
		ft_execute_pipes(data, head);
}
