/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:23:41 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/18 20:49:36 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_execute_not_rebuiltins(t_data *data)
{
	if (ft_strncmp(data->command->content, "cd", 2) == 0)
	{
		if (data->cmd->command[2] != ' ' && data->cmd->command[2] != '\0')
			return (ft_command_not_found(data));
		return (ft_cd(data));
	}
	else if (ft_strncmp(data->command->content, "export", 6) == 0)
	{
		if (data->cmd->command[6] != ' ' && data->cmd->command[6] != '\0')
			return (ft_command_not_found(data));
		return (ft_export(data));
	}
	else if (ft_strncmp(data->command->content, "unset", 5) == 0)
	{
		if (data->cmd->command[5] != ' ' && data->cmd->command[5] != '\0')
			return (ft_command_not_found(data));
		return (ft_unset(data));
	}
	else if (ft_strncmp(data->command->content, "exit", 4) == 0)
	{
		if (data->cmd->command[4] != ' ' && data->cmd->command[4] != '\0')
			return (ft_command_not_found(data));
		return (ft_exit(data));
	}
	return (0);
}

int	ft_execute_rebuiltins(t_data *data)
{
	data->cmd->command = data->command->content;
	if (ft_strncmp(data->command->content, "echo", 4) == 0)
	{
		if (data->cmd->command[4] != ' ' && data->cmd->command[4] != '\0')
			return (ft_command_not_found(data));
		else
			return (ft_echo(data));
	}
	else if (ft_strncmp(data->command->content, "pwd", 3) == 0)
	{
		if (data->cmd->command[3] != ' ' && data->cmd->command[3] != '\0')
			return (ft_command_not_found(data));
		else
			return (ft_pwd(data));
	}
	else if (ft_strncmp(data->command->content, "env", 3) == 0)
	{
		if (data->cmd->command[3] != ' ' && data->cmd->command[3] != '\0')
			return (ft_command_not_found(data));
		else
			return (ft_env(data));
	}
	return (0);
}

int	ft_not_redirected_builtins(t_data *data)
{
	data->cmd->command = data->command->content;
	if (ft_strncmp(data->command->content, "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(data->cmd->command, "export", 6) == 0)
		return (1);
	else if (ft_strncmp(data->command->content, "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(data->command->content, "exit", 4) == 0)
		return (1);
	return (0);
}

int	ft_is_redirected_builtins(t_data *data)
{
	if (ft_strncmp(data->command->content, "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(data->command->content, "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(data->command->content, "env", 3) == 0)
		return (1);
	return (0);
}
