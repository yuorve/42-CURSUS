/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 19:31:43 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 15:19:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	inter1;
	size_t	inter2;

	inter1 = 0;
	if (!*needle)
		return ((char *)&haystack[inter1]);
	while (haystack[inter1] != '\0' && inter1 < len)
	{
		inter2 = 0;
		while (haystack[inter1 + inter2] != '\0'
			&& haystack[inter1 + inter2] == needle[inter2]
			&& inter1 + inter2 < len)
		{
			if (needle[inter2 + 1] == '\0')
				return ((char *)&haystack[inter1]);
			inter2++;
		}
		inter1++;
	}
	return (0);
}
