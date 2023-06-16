/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/06/16 18:00:13 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ejecutar pa y pb
void	push(int *stack_a, int *stack_b, char c, int size)
{
	int	i;
	int	tmp;

	i = -1;
	if (c == 'a')
	{
		tmp = stack_b[0];
		while (++i < stack_size(stack_b))
			stack_b[i] = stack_b[i + 1];
		stack_a[size] = '\0';
		while (--size > 0)
			stack_a[size] = stack_a[size - 1];
		stack_a[size] = tmp;
	}
	else
	{
		tmp = stack_a[0];
		while (++i < stack_size(stack_a))
			stack_a[i] = stack_a[i + 1];
		stack_b[size] = '\0';
		while (--size > 0)
			stack_b[size] = stack_b[size - 1];
		stack_b[size] = tmp;
	}
	ft_printf("p%c\n", c);
}

// Función para ejecutar sa sb
void	swap(int *stack, char c)
{
	int	tmp;

	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	ft_printf("s%c\n", c);
}

// Función para ejecutar ra rb
void	rotate(int *stack, int size, char c)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack[0];
	while (i < (size - 1))
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
	ft_printf("r%c\n", c);
}

// Función para ejecutar rra rrb
void	rev_rotate(int *stack, int size, char c)
{
	int	i;
	int	tmp;

	i = size - 1;
	tmp = stack[i];
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
	ft_printf("rr%c\n", c);
}
