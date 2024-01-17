/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:03:45 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/17 21:25:22 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_check_parameter(t_data *data, char *param_content)
{
	if (ft_strchr(param_content, '=') != NULL)
	{
		printf("minishell: unset: `%s': not a valid identifier\n",
			param_content);
		data->cmd->exit_status = 1;
		return (1);
	}
	else if (ft_is_numeric(param_content) == 0)
	{
		printf("minishell: unset: `%s': not a valid identifier\n",
			param_content);
		data->cmd->exit_status = 1;
		return (1);
	}
	data->cmd->exit_status = 0;
	return (0);
}

int	ft_check_and_remove(t_data *data, t_env_node **env_list, t_list *parameters)
{
	t_env_node	*current;
	t_env_node	*prev;

	current = *env_list;
	prev = NULL;
	while (current != NULL)
	{
		if (ft_check_parameter(data, parameters->content) == 1)
		{
			if (parameters->next == NULL)
				return (1);
			break ;
		}
		if (ft_strcmp(current->name, parameters->content) == 0)
		{
			if (prev == NULL)
				*env_list = current->next;
			prev->next = current->next;
			ft_free_node(current);
			break ;
		}
		prev = current;
		current = current->next;
	}
	return (0);
}

int	ft_unset(t_data *data)
{
	t_env_node	*prev;
	t_list		*parameters;

	prev = NULL;
	parameters = data->parameter;
	while (parameters)
	{
		if (ft_check_and_remove(data, &(data->env_list), parameters) == 1)
			return (1);
		parameters = parameters->next;
	}
	return (0);
}
