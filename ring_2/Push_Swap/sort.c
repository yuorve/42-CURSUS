/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:49:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/18 11:51:55 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ejecutar pa pb
void	push(int *stack_a, int *stack_b, char c, int size)
{
	int	i;
	int	tmp;

	i = -1;
	if (c == 'a')
	{
		tmp = stack_b[0];
		while (++i < (size - 1))
			stack_b[i] = stack_b[i + 1];
		while (i > 0)
		{
			stack_a[i] = stack_a[i - 1];
			i--;
		}
		stack_a[i] = tmp;
	}
	else
	{
		tmp = stack_a[0];
		while (++i < (size - 1))
			stack_a[i] = stack_a[i + 1];
		while (i > 0)
			stack_b[i] = stack_b[i-- - 1];
		stack_b[i] = tmp;
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

// Función para ordenar pilas de 3 o menos elementos
void	sort_small(int *stack_a, int size)
{
	if (size == 2)
		swap(stack_a, 'a');
	else
	{
		if (stack_a[1] > stack_a[2])
		{
			if (stack_a[1] < stack_a[0])
			{
				rotate(stack_a, size, 'a');
				swap(stack_a, 'a');
			}
			else
			{
				rotate(stack_a, size, 'a');
				rotate(stack_a, size, 'a');
			}
		}
		else
			swap(stack_a, 'a');
	}
}

// Función para ordenar pilas de más de 3 elementos
void	sort_large(int *stack_a, int *stack_b, int size)
{
	int	i;
	int	j;
	int	*stack_tmp;

	stack_tmp = malloc (size * sizeof(int *));
	i = 0;
	while (i < size)
	{
		stack_tmp[i] = stack_a[i];
		i++;
	}
	radix_sort(stack_tmp, size);
	i = 0;
	j = 0;
	while (i < size)
	{
		if ((size - i) <= 3)
		{
			sort_small(stack_a, size);
			i = size;
		}
		else
		{
			if (stack_a[1] < stack_a[0])
				swap(stack_a, 'a');
			if (stack_a[0] == stack_tmp[i])
			{
				push(stack_a, stack_b, 'b', size);
				i++;
				j++;
			}
			else
				rotate(stack_a, size, 'a');
		}
	}
	i = 0;
	while (i < j)
	{
		push(stack_a, stack_b, 'a', size);
		i++;
	}
	free(stack_tmp);
}
