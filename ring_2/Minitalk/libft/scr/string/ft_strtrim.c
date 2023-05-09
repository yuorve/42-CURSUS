/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:58:24 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/25 19:31:35 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	size_t	i;
	size_t	len;

	if (!set)
		return (ft_strdup((char *)s1));
	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (len > 0 && ft_strchr(set, s1[len]))
		len--;
	tab = ft_substr(s1, i, (len - i + 1));
	return (tab);
}
