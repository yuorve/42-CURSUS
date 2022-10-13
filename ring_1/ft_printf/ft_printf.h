/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 07:47:26 by yoropeza          #+#    #+#             */
/*   Updated: 2022/10/13 10:40:41 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putchar(char c, int *ptrlen);
void	ft_putstr(char *s, int *ptrlen);
void	ft_toptr(unsigned long n, int *ptr);
void	ft_putnbr(int n, int *ptr);
void	ft_putunbr(unsigned int n, int *ptr);
void	ft_tohex(unsigned int n, char c, int *ptr);
void	ft_checking(char c, va_list args, int *ptr);

int		ft_printf(char const *str, ...);

#endif