/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:17:32 by yoropeza          #+#    #+#             */
/*   Updated: 2022/08/17 19:50:58 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = (char *) malloc (sizeof(char) * (ft_strlen(src) + 1))))
		return ('\0');
	while (*src)
		tab[i++] = *src++;
	tab[i] = '\0';
	return (tab);
}
