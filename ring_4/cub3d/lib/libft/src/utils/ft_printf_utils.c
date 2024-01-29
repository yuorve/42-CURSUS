/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:54:14 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 09:51:53 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putchar(char c, int *ptr)
{
	*ptr += write(1, &c, 1);
}

void	ft_putstr(char *s, int *ptr)
{
	int	i;

	i = 0;
	if (s == NULL)
		ft_putstr("(null)", ptr);
	else
	{
		while (s[i])
		{
			ft_putchar(s[i], ptr);
			i++;
		}
	}
}

void	ft_toptr(unsigned long n, int *ptr)
{
	unsigned long	c;

	if (n >= 16)
		ft_toptr(n / 16, ptr);
	n %= 16;
	c = 48;
	if (n >= 10)
		c = 87;
	ft_putchar(n + c, ptr);
}

void	ft_putnbr(int n, int *ptr)
{
	long	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', ptr);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10, ptr);
	ft_putchar(nb % 10 + '0', ptr);
}

void	ft_putunbr(unsigned int n, int *ptr)
{
	if (n > 9)
		ft_putnbr(n / 10, ptr);
	ft_putchar(n % 10 + '0', ptr);
}
