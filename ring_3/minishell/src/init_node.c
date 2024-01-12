/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:33:58 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/12 19:27:50 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_count_nodes(t_env_node *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

t_env_node	*ft_create_env_node(char *name, char *value)
{
	t_env_node	*new_node;

	new_node = (t_env_node *)malloc(sizeof(t_env_node));
	if (new_node)
	{
		new_node->name = ft_strdup(name);
		new_node->value = ft_strdup(value);
		new_node->next = NULL;
	}
	return (new_node);
}

t_env_node	*ft_listlast(t_env_node *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_push_env_node(t_env_node **head, char *name, char *value)
{
	t_env_node	*curr;
	t_env_node	*new_node;

	new_node = ft_create_env_node(name, value);
	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		curr = ft_listlast(*head);
		curr->next = new_node;
	}
}

t_env_node	*ft_find_node(t_env_node *head, const char *name)
{
	while (head != NULL)
	{
		if (ft_strcmp(head->name, name) == 0)
		{
			return (head);
		}
		head = head->next;
	}
	return (0);
}
