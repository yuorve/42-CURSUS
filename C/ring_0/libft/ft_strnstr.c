/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:31:43 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/24 19:55:04 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len == 0)
		return (0);
	if (*needle)
	{
		while (*haystack && len > 0)
		{
			if (*haystack == *needle)
			{
				needle++;
			}
			haystack++;
			len--;
		}
		if (*needle)
			return (0);
	}
	return ((char *)haystack);
}
