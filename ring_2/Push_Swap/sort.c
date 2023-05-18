/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:49:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/18 12:17:30 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// Función de apoyo para ordenar pilas de más de 3 elementos
// Si devuelve 1 ha habido un push
int	sorting(int *stack_a, int *stack_tmp, int i)
{
	if (stack_a[1] < stack_a[0])
		swap(stack_a, 'a');
	if (stack_a[0] == stack_tmp[i])
	{
		push(stack_a, stack_b, 'b', size);
		return (1);
	}
	else
		rotate(stack_a, size, 'a');
	return (0);
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
			if (sorting(stack_a, stack_tmp, i))
			{
				i++;
				j++;
			}
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
