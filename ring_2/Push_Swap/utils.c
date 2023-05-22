/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:23:57 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/22 12:31:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para saber la longitud de la pila
int	stack_size(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		i++;
	}
	return (i);
}

// ATOI para un valor superior al int
long	ft_atoil(const char *str)
{
	int		i;
	long	number;
	long	negative;

	i = 0;
	number = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (str[i] - '0');
		str++;
	}
	return (number * negative);
}

// Función para buscar duplicados dentro de la pila
// Aprovecho la misma función para comprobar
// Cualquier valor superior al int
// Devuelve 1 si hay duplicados 0 sino
int	has_dupe(int *stack_a, long n)
{
	int	i;
	int	valid;

	i = 0;
	valid = 0;
	if (n > 2147483647)
		valid = 1;
	if (n < -2147483648)
		valid = 1;
	while (stack_a[i])
	{
		if (stack_a[i] == n)
			valid = 1;
		i++;
	}
	return (valid);
}

// Función para decidir si se hacer reverse
void	direction(int *stack, int size)
{
	if (stack[0] > stack[1])
		swap(stack, 'a');
	else if (stack[0] < stack[(size - 1)])
		rotate(stack, size, 'a');
	else
		rev_rotate(stack, size, 'a');
}
