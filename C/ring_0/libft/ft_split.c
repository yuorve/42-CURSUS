/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:24:31 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/28 16:41:51 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	i;
	int	num_words;

	num_words = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			num_words++;
		i++;
	}
	return (num_words + 1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		num_words;
	int		start;
	char	**matrix;

	if (!s)
		return (0);
	matrix = (char **) malloc (sizeof(char *) * (count_words(s, c) + 1));
	if (!matrix)
		return (0);
	i = 0;
	num_words = 0;
	while (s[i] && num_words < count_words(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		matrix[num_words++] = ft_substr(s, start, (i - start));
	}
	matrix[num_words] = 0;
	return (matrix);
}
