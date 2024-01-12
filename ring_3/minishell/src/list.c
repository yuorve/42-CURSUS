/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:13:40 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/12 20:15:18 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_list	*ft_previously(t_list *list, t_list *target)
{
	t_list	*curr;

	if (!list)
		return (0);
	curr = list;
	while (curr->next)
	{
		if (curr->next == target)
			return (curr);
		curr = curr->next;
	}
	return (0);
}

t_list	*ft_add_to_list(t_list *list, char *content)
{
	if (!list)
		list = ft_lstnew(ft_strtrim(content, " "));
	else
		ft_lstadd_back(&list, ft_lstnew(ft_strtrim(content, " ")));
	return (list);
}

char	**ft_list_to_matrix(t_env_node *head)
{
	int			i;
	char		**env_matrix;
	char		*leak_prevent;
	t_env_node	*curr;

	i = 0;
	curr = head;
	env_matrix = (char **)calloc(sizeof(char **), ft_count_nodes(curr) + 1);
	while (curr)
	{
		leak_prevent = ft_strjoin(curr->name, "=");
		env_matrix[i] = ft_strjoin(leak_prevent, curr->value);
		free(leak_prevent);
		i++;
		curr = curr->next;
	}
	env_matrix[i] = NULL;
	return (env_matrix);
}
