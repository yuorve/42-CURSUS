/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:39:27 by yoropeza          #+#    #+#             */
/*   Updated: 2023/11/24 21:24:00 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	lens1;
// 	size_t	lens2;
// 	size_t	i;
// 	char	*tab;

// 	lens1 = ft_strlen(s1);
// 	lens2 = ft_strlen(s2);
// 	tab = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	while (*s1)
// 	{
// 		tab[i] = *s1;
// 		s1++;
// 		i++;
// 	}
// 	while (*s2)
// 	{
// 		tab[i] = *s2;
// 		s2++;
// 		i++;
// 	}
// 	tab[i] = '\0';
// 	return (tab);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *) malloc (sizeof(char) * len);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		dst[j++] = s2[i++];
	}
	dst[j] = '\0';
	return (dst);
}


