/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:39:27 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 18:01:43 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	inter;
	char	*tab;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	tab = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (!tab)
		return (0);
	inter = 0;
	while (*s1)
	{
		tab[inter] = *s1;
		s1++;
		inter++;
	}
	while (*s2)
	{
		tab[inter] = *s2;
		s2++;
		inter++;
	}
	tab[inter] = '\0';
	return (tab);
}
