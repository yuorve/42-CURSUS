/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:46:09 by yoropeza          #+#    #+#             */
/*   Updated: 2024/02/27 19:14:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_tohex(unsigned int n, char c, int *ptr)
{
	int	ch;

	if (n >= 16)
		ft_tohex(n / 16, c, ptr);
	n = n % 16;
	ch = 48;
	if (n >= 10 && c == 'X')
		ch = 55;
	else if (n >= 10 && c == 'x')
		ch = 87;
	ft_putchar(n + ch, ptr);
}

void	ft_checking(char c, va_list args, int *ptr)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, int), ptr);
	if (c == 's')
		ft_putstr(va_arg(args, char *), ptr);
	if (c == 'p')
	{
		ft_putstr("0x", ptr);
		ft_toptr(va_arg(args, long), ptr);
	}
	if (c == 'd')
		ft_putnbr(va_arg(args, int), ptr);
	if (c == 'i')
		ft_putnbr(va_arg(args, int), ptr);
	if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), ptr);
	if (c == 'x' || c == 'X')
		ft_tohex(va_arg(args, int), c, ptr);
	if (c == '%')
		ft_putchar('%', ptr);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		*ptr;

	i = 0;
	len = 0;
	ptr = &len;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar(str[i], ptr);
		else
		{
			i++;
			ft_checking(str[i], args, ptr);
		}
		i++;
	}
	va_end(args);
	return (len);
}
