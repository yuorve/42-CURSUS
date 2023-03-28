/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:18 by yoropeza          #+#    #+#             */
/*   Updated: 2022/11/01 18:13:10 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *) malloc (sizeof(char) * (ft_strlen(src) + 1));
	if (!tab)
		return (NULL);
	while (*src)
		tab[i++] = *src++;
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ret;

	ret = (unsigned char)c;
	while (*s != ret)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char *)s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	tab = (char *) malloc (sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		tab[i] = s[start + i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens1;
	size_t	lens2;
	size_t	i;
	char	*tab;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	tab = (char *) malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s1)
	{
		tab[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		tab[i] = *s2;
		s2++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
