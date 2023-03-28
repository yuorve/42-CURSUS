/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:21:21 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 15:37:28 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*tab;

	tab = (char *) malloc (sizeof(char) * (nitems * size));
	if (tab)
		ft_bzero(tab, (nitems * size));
	return (tab);
}
