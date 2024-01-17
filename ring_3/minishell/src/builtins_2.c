/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:59:56 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/17 21:31:20 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_pwd(t_data *data)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("Error al obtener el directorio de trabajo actual");
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	data->cmd->exit_status = 0;
	return (0);
}

int	ft_echo(t_data *data)
{
	t_list	*current;

	if (ft_lstsize(data->parameter) > 0)
	{
		current = data->parameter;
		if (ft_strncmp(current->content, "-n", 2) == 0)
			current = current->next;
		while (current)
		{
			ft_printf("%s", current->content);
			current = current->next;
			if (current)
				ft_printf(" ");
		}
		if (ft_strncmp(data->parameter->content, "-n", 2) != 0)
			ft_printf("\n");
	}
	else
		ft_printf("\n");
	data->cmd->exit_status = 0;
	return (0);
}

int	ft_is_numeric(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			return (1);
		}
		str++;
	}
	return (0);
}

int	ft_exit(t_data *data)
{
	int	exit_code;

	exit_code = 0;
	if (data->parameter)
	{
		if (ft_is_numeric(data->parameter->content) == 1)
			ft_exit_num_error(data);
		else
		{
			exit_code = ft_atoi(data->parameter->content);
			if (ft_lstsize(data->parameter) > 1)
			{
				printf("minishell: exit: too many arguments\n");
				return (1);
			}
			if (exit_code > 255)
			{
				data->cmd->exit_status = exit_code % 256;
				exit (exit_code % 256);
			}
		}
	}
	exit(exit_code);
}

int	ft_env(t_data *data)
{
	t_env_node	*head;

	if (data->parameter == NULL)
	{
		head = data->env_list;
		while (head)
		{
			if (head->name != NULL && head->value != NULL
				&& ft_strlen(head->value) > 0)
			{
				printf("%s=%s\n", head->name, head->value);
			}
			head = head->next;
		}
		data->cmd->exit_status = 0;
		return (0);
	}
	else
	{
		printf ("env: No such file or directory\n");
		data->cmd->exit_status = 127;
		return (127);
	}
}
