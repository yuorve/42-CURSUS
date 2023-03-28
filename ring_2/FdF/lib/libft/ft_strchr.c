/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:21:08 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/24 19:22:47 by yoropeza         ###   ########.fr       */
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
