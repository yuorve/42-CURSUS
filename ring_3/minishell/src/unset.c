/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:03:45 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/11 21:04:07 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int ft_check_parameter(t_data *data)
{
	if (ft_strchr(data->parameter->content, '=') != NULL)
	{
		printf("minishell: unset: `%s': not a valid identifier\n", data->parameter->content);
		data->cmd->exit_status = 1;
		return (1);
	}
	else if (ft_is_numeric(data->parameter->content) == 0)
	{
		printf("minishell: unset: `%s': not a valid identifier\n",data->parameter->content);
		data->cmd->exit_status = 1;
		return (1);
	}
	return (0);
}


int ft_unset(t_data *data)
{
	t_env_node *current;
	t_env_node *prev;

	prev = NULL;
	current = data->env_list;
	while (current != NULL)
	{
		if (ft_check_parameter(data) == 1)
			return (1);
		if (ft_strcmp(current->name, data->parameter->content) == 0)
		{
			if (prev == NULL)
				data->env_list = current->next; // Si el nodo a eliminar es el primero
			else
				prev->next = current->next;
			ft_free_node(current);
			return (0); // despues de eliminar la variable de entorno
		}
		prev = current;
		current = current->next;
	}
	return (0); // Si la variable de entorno no se encuentra
}
