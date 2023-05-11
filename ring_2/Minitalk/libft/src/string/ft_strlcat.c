/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:08:43 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 09:52:57 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dest, char *scr, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_s;
	size_t	len_d;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	len_d = i;
	len_s = ft_strlen(scr);
	if (size == 0 || size <= i)
		return (len_s + size);
	while (scr[j] && j < size - len_d - 1)
	{
		dest[i] = scr[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_d + len_s);
}
