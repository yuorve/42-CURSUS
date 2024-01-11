/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:54:48 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 21:05:12 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int    ft_check_export_errors(t_data *data)
{
	t_list *parameter;

	parameter = data->parameter;
	while(parameter)
	{
		//compruebo
		data->cmd->param = parameter->content;
		if(ft_isalpha(data->cmd->param[0]) == 0 && data->cmd->param[0] != '_')
		{
			printf("minishell: export: `%s': not a valid identifier\n", data->cmd->param);
			data->cmd->exit_status = 1;
			return(1);
		}
		parameter = parameter->next;
	}
	return(0);
}


int ft_exists_variable(t_data *data, char *param_content, char *value)
{
	t_env_node *current;
	int found;

	current = data->env_list;
	found = 0;
	while (current)
	{
		if (ft_strcmp(current->name, param_content) == 0)
		{
			// Variable exists, update its value only if a new value is provided and it's different
			if (*value != '\0' && ft_strcmp(current->value, value) != 0)
			{
				free(current->value);
				current->value = ft_strdup(value);
			}
			found = 1;
			break;
		}
		current = current->next;
	}
	if (!found)
		ft_push_env_node(&data->env_list, param_content, value, data->env_list->equal);
	return (0);
}


char	ft_find_variable(t_data *data, t_list *tmp)
{
	char *param_content;
	char *value;

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

	// t_env_node *current;
	// int found;

	// current = data->env_list;
	// found = 0;
	// while (current)
	// {
	// 	if (ft_strcmp(current->name, param_content) == 0)
	// 	{
	// 		// Variable exists, update its value only if a new value is provided and it's different
	// 		if (*value != '\0' && ft_strcmp(current->value, value) != 0)
	// 		{
	// 			free(current->value);
	// 			current->value = ft_strdup(value);
	// 		}
	// 		found = 1;
	// 		break;
	// 	}
	// 	current = current->next;
	// }
	// if (!found)
	// 	ft_push_env_node(&data->env_list, param_content, value, data->env_list->equal);

	return (0);
}


int ft_export(t_data *data)
{
	if (data->parameter == NULL && (data->cmd->command[6] == ' ' || data->cmd->command[6] == '\0'))
	{
		ft_print_sorted_env(data->env_list);
		return (0);
	}
	// else if (data->cmd->command[6] != ' ')
	//     return (ft_command_not_found(data));
	else
	{
		t_list *tmp;

		tmp = data->parameter;
		if (ft_check_export_errors(data) == 0)
		{
			while (tmp)
			{
				ft_find_variable(data, tmp);
				// char *param_content = tmp->content;
				// char *value = ft_strchr(param_content, '=');

				// if (value != NULL)
				// {
				// 	*value = '\0';
				// 	value++;
				// }
				// else
				// {
				// 	value = "";
				// }

				// t_env_node *current = data->env_list;
				// int found = 0;

				// while (current)
				// {
				// 	if (ft_strcmp(current->name, param_content) == 0)
				// 	{
				// 		// Variable exists, update its value only if a new value is provided and it's different
				// 		if (*value != '\0' && ft_strcmp(current->value, value) != 0)
				// 		{
				// 			free(current->value);
				// 			current->value = ft_strdup(value);
				// 		}
				// 		found = 1;
				// 		break;
				// 	}
				// 	current = current->next;
				// }
				// if (!found)
				// {
				// 	//ft_push_env_node(&data->env_list, param_content, value);
				// 	ft_push_env_node(&data->env_list, param_content, value, data->env_list->equal);
				// }
				tmp = tmp->next;
			}
		}
		return (0);
	}
}
