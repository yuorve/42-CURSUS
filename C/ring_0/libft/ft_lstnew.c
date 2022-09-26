/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:22:28 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/26 17:25:30 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
    t_list  *node;
    
    node = (t_list *) malloc (sizeof(t_list));
    if (!node)
        return (0);
    node->content = content;
    node->next = NULL;
    return (node);
}
