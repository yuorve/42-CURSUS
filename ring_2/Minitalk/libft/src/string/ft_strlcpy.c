/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:21:09 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 09:53:04 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcpy(char *dest, char *scr, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(scr);
	i = 0;
	if (size != 0)
	{
		while (scr[i] != '\0' && i < (size - 1))
		{
			dest[i] = scr[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (len);
}
