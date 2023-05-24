/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:20:42 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/24 11:36:01 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ordenar los elementos al volver a la pila 
void	back_sorting(int *stack_a, int *stack_b)
{
	int	size;

	while (!is_sorted(stack_a, stack_size(stack_a), 0))
	{
		size = stack_size(stack_a);
		if (stack_a[0] > stack_a[size - 1])
			rev_rotate(stack_a, size, 'a');
		else if (stack_a[0] > stack_a[1])
			swap(stack_a, 'a');
		else
			push(stack_a, stack_b, 'b', stack_size(stack_b) + 1);
	}
}

// Función para devolver el tercio a la pila original
void	come_back(int *stack_a, int *stack_b)
{
	while (stack_size(stack_b) > 0)
	{		
		push(stack_a, stack_b, 'a', stack_size(stack_a) + 1);
		if (stack_size(stack_a) <= 3)
			sort_small(stack_a, stack_size(stack_a));
		else
			back_sorting(stack_a, stack_b);
	}
}

// Función para ordenar los elementos enviados a la pila b
void	forward_sorting(int *stack_a, int *stack_b)
{
	int	size;

	while (!is_sorted(stack_b, stack_size(stack_b), 1))
	{
		size = stack_size(stack_b);
		if (size > 1)
		{	
			if (stack_b[0] < stack_b[size - 1])
				rotate(stack_b, size, 'b');
			else if (stack_b[0] < stack_b[1])
				swap(stack_b, 'b');
			else
				push(stack_a, stack_b, 'a', stack_size(stack_b) + 1);
		}
	}
}

// Función para pre-ordenar por tercios
void	split_stack(int *stack_a, int *stack_b, int min, int max)
{
	int	i;

	i = -1;
	while (++i < stack_size(stack_a))
	{
		if (stack_a[0] > min && stack_a[0] <= max)
		{			
			push(stack_a, stack_b, 'b', stack_size(stack_b) + 1);
			i--;
		}
		else
			rotate(stack_a, stack_size(stack_a), 'a');
	}
}

// Función para divir en tercios las pilas grandes ( > 25)
void	pre_sort(int *stack_a, int *stack_b, int size)
{
	int	j;
	int	max;
	int	min;

	j = 0;
	while (++j < 4)
	{
		min = ((size / 3) * (j - 1));
		max = ((size / 3) * j);
		split_stack(stack_a, stack_b, min, max);
		come_back(stack_a, stack_b);
	}		
}
