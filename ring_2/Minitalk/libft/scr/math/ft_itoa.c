/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:31:34 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 09:55:20 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_nblen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;

	len = ft_nblen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = (char *) malloc (sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	tab[len--] = '\0';
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		tab[len--] = n % 10 + '0';
		n /= 10;
	}
	return (tab);
}
