/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:54:48 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/19 19:13:40 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_export_error(t_data *data)
{
	printf("minishell: export:");
	printf(" `%s': not a valid identifier\n", data->cmd->param);
	data->cmd->exit_status = 1;
}

int	ft_check_export_errors(t_data *data)
{
	t_list	*parameter;

	parameter = data->parameter;
	while (parameter)
	{
		data->cmd->param = parameter->content;
		if (ft_isalpha(data->cmd->param[0]) == 0 && data->cmd->param[0] != '_')
		{
			ft_export_error(data);
			return (data->cmd->exit_status);
		}
		parameter = parameter->next;
	}
	data->cmd->exit_status = 0;
	return (0);
}

int	ft_exists_variable(t_data *data, char *param_content, char *value)
{
	t_env_node	*current;
	int			found;

	current = data->env_list;
	found = 0;
	while (current)
	{
		if (ft_strcmp(current->name, param_content) == 0)
		{
			if (*value != '\0' && ft_strcmp(current->value, value) != 0)
			{
				free(current->value);
				current->value = ft_strdup(value);
			}
			found = 1;
			break ;
		}
		current = current->next;
	}
	if (!found)
		ft_push_env_node(&data->env_list, param_content, value);
	return (0);
}

char	ft_find_variable(t_data *data, t_list *tmp)
{
	char	*param_content;
	char	*value;

	param_content = tmp->content;
	value = ft_strchr(param_content, '=');
	if (value != NULL)
	{
		*value = '\0';
		value++;
	}
	else
		value = "";
	ft_exists_variable(data, param_content, value);
	return (0);
}

int	ft_export(t_data *data)
{
	t_list	*tmp;

	if (data->parameter == NULL && (data->cmd->command[6] == ' '
			|| data->cmd->command[6] == '\0'))
	{
		ft_print_sorted_env(data->env_list);
		return (0);
	}
	else
	{
		tmp = data->parameter;
		if (ft_check_export_errors(data) == 0)
		{
			while (tmp)
			{
				ft_find_variable(data, tmp);
				tmp = tmp->next;
			}
		}
		return (0);
	}
}
