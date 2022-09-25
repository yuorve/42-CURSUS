/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 18:48:33 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	inter;
	size_t	len;

	if (!set)
		return (ft_strdup((char *)s1));
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	inter = 0;
	while (s1[inter] && ft_strchr(set, s1[inter]))
		inter++;
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	tab = ft_substr(s1, inter, (len - inter + 1));
	return (tab);
}
