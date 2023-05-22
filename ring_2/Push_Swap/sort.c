/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:49:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/22 12:28:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ordenar pilas de 3 - opcion 2
void	sort_small_2(int *stack_a, int size)
{
	if (stack_a[2] > stack_a[0])
	{
		swap(stack_a, 'a');
	}
	else
	{
		rotate(stack_a, size, 'a');
	}
}

// Función para ordenar pilas de 3 - opcion 3
void	sort_small_3(int *stack_a, int size)
{
	if (stack_a[2] < stack_a[0])
	{
		rev_rotate(stack_a, size, 'a');
	}
	else
	{
		swap(stack_a, 'a');
		rotate(stack_a, size, 'a');
	}
}

// Función para ordenar pilas de 3 o menos elementos
void	sort_small(int *stack_a, int size)
{
	if (size == 2)
		swap(stack_a, 'a');
	else
	{
		if (stack_a[0] > stack_a[1] && stack_a[1] > stack_a[2])
		{
			swap(stack_a, 'a');
			rev_rotate(stack_a, size, 'a');
		}
		else if (stack_a[0] > stack_a[1] && stack_a[1] < stack_a[2])
		{
			sort_small_2(stack_a, size);
		}
		else if (stack_a[0] < stack_a[1] && stack_a[1] > stack_a[2])
		{
			sort_small_3(stack_a, size);
		}
	}
}

// Función de apoyo para ordenar pilas de más de 3 elementos
// Devuelve el número de elementos movidos a la pila b
int	sorting(int *stack_a, int *stack_b, int *stack_tmp, int len_tmp)
{	
	int	i;
	int	len_a;
	int	len_b;

	i = 0;
	len_a = len_tmp;
	len_b = 0;
	while (i < len_tmp && !is_sorted(stack_a, len_a))
	{		
		if (len_a <= 3)
			sort_small(stack_a, len_a);
		else
		{
			if (stack_a[0] == stack_tmp[i])
			{
				push(stack_a, stack_b, 'b', len_a);
				len_a--;
				len_b++;
				i++;
			}
			else
				direction(stack_a, len_a);
		}	
	}
	return (len_b);
}

// Función para ordenar pilas de más de 3 elementos
void	sort_large(int *stack_a, int *stack_b, int size)
{
	int	i;
	int	len_b;
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
	len_b = sorting(stack_a, stack_b, stack_tmp, size);
	while (i < len_b)
	{
		push(stack_a, stack_b, 'a', len_b);
		i++;
	}
	free(stack_tmp);
}
