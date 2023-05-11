/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:33:06 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 09:54:50 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tab;
	unsigned char	ret;

	ret = (unsigned char)c;
	tab = (unsigned char *)str;
	while (n > 0)
	{
		if (*tab == ret)
		{
			return (tab);
		}
		tab++;
		n--;
	}
	return (0);
}
