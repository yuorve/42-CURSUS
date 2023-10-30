/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:09:11 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 09:56:28 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_ft;
	t_list	*final_lst;

	if (!lst || !f)
		return (0);
	final_lst = 0;
	while (lst != 0)
	{
		new_ft = (t_list *) malloc (sizeof(t_list));
		if (!new_ft)
		{
			ft_lstclear(&new_ft, del);
			ft_lstclear(&final_lst, del);
			return (0);
		}
		new_ft->content = f(lst->content);
		new_ft->next = 0;
		ft_lstadd_back(&final_lst, new_ft);
		lst = lst->next;
	}
	return (final_lst);
}
