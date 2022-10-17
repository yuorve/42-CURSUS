/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:58:18 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/17 11:40:12 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ret;

	ret = (unsigned char)c;
	while (*s != ret)
	{
		if (*s == '\0')
		{
			return (0);
		}
		s++;
	}
	return ((char *)s);
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
		return (0);
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
