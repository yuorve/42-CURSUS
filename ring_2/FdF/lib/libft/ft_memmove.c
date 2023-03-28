/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 20:12:17 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 16:50:56 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
	{
		return (0);
	}
	while (i < len)
	{
		if (dst < src)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		else
			((unsigned char *)dst)[len - i - 1]
				= ((unsigned char *)src)[len - i - 1];
		i++;
	}
	return (dst);
}
