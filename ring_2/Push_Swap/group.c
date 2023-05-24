/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:20:42 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/24 08:01:36 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ordenar los elementos al volver a la pila 
void	back_sorting(int *stack)
{
	int	size;
	
	size = stack_size(stack_a);
	while (!is_sorted(stack, size))
	{
		if (stack[0] > stack[1])
			swap(stack, 'a');
		else if (stack[0] > stack[size - 1])
			rev_rotate(stack, size, 'a');
		else
			rotate(stack, size, 'a');
	}
}

// Función para devolver el tercio a la pila original
void	come_back(int *stack_a, int *stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{		
		push(stack_a, stack_b, 'a', stack_size(stack_a) + 1);
		back_sorting(stack_a);
		i++;
	}
}

// Función para pre-ordenar por tercios
void	split_stack(int *stack_a, int *stack_b, int min, int max)
{
	int	i;
	int	size;

	size = stack_size(stack_a);
	i = -1;
	while (++i < size)
	{
		if (stack_a[0] > min && stack_a[0] <= max)
		{
			push(stack_a, stack_b, 'b', stack_size(stack_b) + 1);
			size--;
			i--;
		}
		else
			rotate(stack_a, size, 'a');
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
	}
	come_back(stack_a, stack_b, stack_size(stack_b));
}
