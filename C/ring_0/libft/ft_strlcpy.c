/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:21:09 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/23 20:04:52 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t	ft_strlcpy(char *dest, char *scr, size_t size)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (scr[len] != '\0')
		len++;
	i = 0;
	while (scr[i] != '\0' && i < (size - 1))
	{
		dest[i] = scr[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		++i;
	}
	return (len);
}
