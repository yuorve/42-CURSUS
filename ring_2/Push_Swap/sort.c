/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 09:49:55 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/13 15:38:10 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para terminar de ordenar la pila
void	stacking_final(t_Data *data)
{
	t_Node	*current;

	current = data->stack_a->top;
	while (find_pos(data->tmp->top, current->data) != 0)
		current = current->next;
	if (find_pos(data->stack_a->top, current->data) <= data->average)
		ra(data);
	else if (find_pos(data->stack_a->top, current->data) > data->average)
		rra(data);
	if (find_pos(data->tmp->top, data->stack_a->top->data) != 0)
		stacking_final(data);
}

// Función para mover los elementos una pila
void	stacking(t_Data *data)
{
	while (data->count_a > 0)
	{
		ra(data);
		data->count_a--;
	}
	while (data->count_a < 0)
	{
		rra(data);
		data->count_a++;
	}
	while (data->count_b > 0)
	{
		rb(data);
		data->count_b--;
	}
	while (data->count_b < 0)
	{
		rrb(data);
		data->count_b++;
	}	
}

// Función para mover los elementos de ambas pilas
void	stacking_both(t_Data *data)
{
	while (data->count_a != 0 || data->count_b != 0)
	{
		while (data->count_a > 0 && data->count_b > 0)
		{
			rr(data);
			data->count_a--;
			data->count_b--;
		}
		while (data->count_a < 0 && data->count_b < 0)
		{
			rrr(data);
			data->count_a++;
			data->count_b++;
		}
		stacking(data);
	}
	pa(data);
}

// Función para ordenar pilas de más de 3 elementos
void	sort_2(t_Data *data)
{
	if (!is_sorted_stack(data))
		sort_small(data);
	while (data->stack_b->size > 0)
	{
		calcutate_moves(data);
		stacking_both(data);
	}
	if (!is_sorted_stack(data))
		stacking_final(data);
}

// Función para ordenar pilas de más de 3 elementos
void	sort(t_Data *data)
{
	t_Stack	*stack;
	int		i;

	stack = create_stack();
	data->stack_b = stack;
	data->average = data->stack_a->size / 2;
	i = 0;
	while (i < data->stack_a->size && data->stack_a->size > 3)
	{
		if (find_pos(data->tmp->top, data->stack_a->top->data) < data->average)
			pb(data);
		else
		{
			ra(data);
			i++;
		}
	}
	while (data->stack_a->size > 3)
		pb(data);
	sort_2(data);
	free_stack(stack);
}
