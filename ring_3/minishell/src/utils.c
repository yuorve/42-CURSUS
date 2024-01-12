/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 21:11:27 by angalsty          #+#    #+#             */
/*   Updated: 2024/01/12 19:24:28 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)&haystack[i]);
	while (haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] != '\0'
			&& haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_strxstr(char *str, char *from, char *to)
{
	t_strxstr	xstr;

	ft_bzero(&xstr, sizeof(t_strxstr));
	while (str[xstr.i])
	{
		while (str[xstr.i] && from[xstr.j] && str[xstr.i] == from[xstr.j++])
			xstr.i++;
		if (from[xstr.j])
		{
			xstr.i++;
			xstr.j = 0;
		}
		else
			break ;
	}
	if (from[0] == '$')
		xstr.start = ft_substr(str, 0, (xstr.i - xstr.j));
	else
		xstr.start = ft_substr(str, 0, (xstr.i - xstr.j) - 1);
	xstr.res = ft_strjoin(xstr.start, to);
	xstr.end = ft_substr(str, xstr.i, ft_strlen(str));
	str = ft_strjoin(xstr.res, xstr.end);
	ft_free3(xstr.start, xstr.res, xstr.end);
	return (str);
}
