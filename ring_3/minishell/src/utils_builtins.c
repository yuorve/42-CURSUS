/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:01:47 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/12 19:29:30 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_swap_values(char **str1, char **str2)
{
	char	*temp;

	temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}

void	ft_sort_env_list(t_env_node **head)
{
	int			swapped;
	t_env_node	*ptr;
	t_env_node	*last;

	last = NULL;
	swapped = 0;
	if (*head == NULL)
		return ;
	while (!swapped)
	{
		swapped = 1;
		ptr = *head;
		while (ptr->next != last)
		{
			if (ft_strcmp(ptr->name, ptr->next->name) > 0)
			{
				ft_swap_values(&(ptr->name), &(ptr->next->name));
				ft_swap_values(&(ptr->value), &(ptr->next->value));
				swapped = 0;
			}
			ptr = ptr->next;
		}
		last = ptr;
	}
}

void	ft_free_node(t_env_node *node)
{
	free(node->name);
	free(node->value);
	free(node);
}

void	ft_print_sorted_env(t_env_node *head)
{
	t_env_node	*temp;
	t_env_node	*sorted_env;

	sorted_env = NULL;
	temp = head;
	while (temp)
	{
		ft_push_env_node(&sorted_env, temp->name, temp->value);
		temp = temp->next;
	}
	ft_sort_env_list(&sorted_env);
	temp = sorted_env;
	while (temp)
	{
		if (temp->name != NULL && temp->value != NULL)
			printf("declare -x %s=\"%s\"\n", temp->name, temp->value);
		temp = temp->next;
	}
	while (sorted_env)
	{
		temp = sorted_env;
		sorted_env = sorted_env->next;
		ft_free_node(temp);
	}
}

int	ft_command_not_found(t_data *data)
{
	printf("minishell: %s: command not found\n", data->cmd->command);
	data->cmd->exit_status = 127;
	return (1);
}
