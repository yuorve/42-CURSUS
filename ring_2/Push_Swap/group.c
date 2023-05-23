/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 08:20:42 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/23 11:41:49 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para devolver el tercio a la pila original
void	come_back(int *stack_a, int *stack_b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push(stack_a, stack_b, 'a', size);
		i++;
	}
}

// Función para pre-ordenar por tercios
void	split_stack(int *stack_a, int *stack_b, int size, int j)
{
	int	i;
	int	len_a;
	int	len_b;

	len_a = size;
	len_b = 0;
	i = -1;
	while (++i < len_a)
	{
		if (stack_a[i] > ((size / 3) * (j - 1))
			&& stack_a[i] <= ((size / 3) * j))
		{
			push(stack_a, stack_b, 'b', len_a);
			len_a--;
			len_b++;
			i--;
		}
		else
			rotate(stack_a, len_a, 'a');
	}
	come_back(stack_a, stack_b, len_b);
}

// Función para divir en tercios las pilas grandes ( > 25)
void	pre_sort(int *stack_a, int *stack_b, int size)
{
	int	j;

	j = 0;
	while (++j < 4)
	{
		split_stack(stack_a, stack_b, size, j);
	}
}
