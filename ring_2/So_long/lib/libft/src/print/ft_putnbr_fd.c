/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:39:10 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/11 11:55:13 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb > -2147483648)
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putnbr_fd((nb / 10), fd);
			nb = nb % 10;
		}
		if (nb < 10)
			ft_putchar_fd((nb + '0'), fd);
	}
	else
		write(fd, "-2147483648", 11);
}
