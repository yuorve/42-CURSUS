/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:09:11 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/28 17:39:14 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_ft;
	t_list	*final_lst;

	if (!lst || !f)
		return (0);
	final_lst = 0;
	while (lst != 0)
	{
		new_ft = ft_lstnew(f(lst->content));
		if (!new_ft)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		ft_lstadd_back(&final_lst, new_ft);
		lst = lst->next;
	}
	return (final_lst);
}
