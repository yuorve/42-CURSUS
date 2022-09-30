/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:39:10 by yoropeza          #+#    #+#             */
/*   Updated: 2022/09/30 18:40:19 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr(int nb, int fd)
{
	if (nb > -2147483648)
	{
		if (nb < 0)
		{
			ft_putchar('-', fd);
			nb = -nb;
		}
		if (nb >= 10)
		{
			ft_putnbr((nb / 10), fd);
			nb = nb % 10;
		}
		if (nb < 10)
			ft_putchar((nb + '0'), fd);
	}
	else
		write(fd, "-2147483648", 11);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
