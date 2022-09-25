/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:40:44 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 17:37:15 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	inter;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	tab = (char *) malloc (sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	inter = 0;
	while (s[start + inter] && inter < len)
	{
		tab[inter] = s[start + inter];
		inter++;
	}
	tab[inter] = '\0';
	return (tab);
}
