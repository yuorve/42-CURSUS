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
void	stackingFinal(t_Data *data)
{
	t_Node *current;

	current = data->stack_a->top;
	while (findPos(data->tmp->top, current->data) != 0)
		current = current->next;
	if (findPos(data->stack_a->top, current->data) <= data->average)
		ra(data);
	else if (findPos(data->stack_a->top, current->data) > data->average)
		rra(data);
	if (findPos(data->tmp->top, data->stack_a->top->data) != 0)
		stackingFinal(data);
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
void	stackingBoth(t_Data *data)
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

// Función para ordenar pilas de 3 o menos
void	sort_small(t_Data *data)
{
	if (data->stack_a->size == 1)
		freeStack(data->stack_a);
	else if (data->stack_a->size == 2 && !isSortedStack(data))
		sa(data);
	else if (data->stack_a->size == 3)
	{
		while (!isSortedStack(data))
		{
			if (findPos(data->stack_a->top, maxStack(data->stack_a->top)) == 0)
				ra(data);
			else if (findPos(data->stack_a->top, maxStack(data->stack_a->top)) == 1)
				rra(data);
			else if (findPos(data->stack_a->top, maxStack(data->stack_a->top)) == 2)
				sa(data);
		}
	}
}

// Función para ordenar pilas de más de 3 elementos
void	sort(t_Data *data)
{
	t_Stack *stack;
	int	i;
	
	stack = createStack();
	data->stack_b = stack;
	data->average = data->stack_a->size / 2;
	i = 0;
	while (i < data->stack_a->size && data->stack_a->size > 3)
	{
		if (findPos(data->tmp->top, data->stack_a->top->data) < data->average)
			pb(data);
		else
		{
			ra(data);
			i++;
		}
    }
	while (data->stack_a->size > 3)
		pb(data);
	if (!isSortedStack(data))
		sort_small(data);
	while (data->stack_b->size > 0)
	{
		calcutateMoves(data);
		stackingBoth(data);
	}
	if (!isSortedStack(data))
		stackingFinal(data);
	freeStack(stack);
}
