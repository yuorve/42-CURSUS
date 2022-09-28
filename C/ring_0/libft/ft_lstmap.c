/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:09:11 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/28 16:38:39 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	new;

	if (lst)
	{
		while (lst)
		{			
			ft_lstadd_back(&new, ft_lstnew(f(lst->content)));
			lst = lst->next;
		}
	}
	return (new);
}
