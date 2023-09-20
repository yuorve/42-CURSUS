/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:17:19 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/13 15:40:02 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para calcular los movimientos necesarios
// para llevar un elemento a la otra pila
int	moves(t_Data *data, int value_to_find, int controller)
{
	int	pos_a;
	int	pos_b;
	int	moves_a;
	int	moves_b;

	pos_a = find_pos(data->stack_a->top, find_next(data, value_to_find));
	pos_b = find_pos(data->stack_b->top, value_to_find);
	if (pos_a > (data->stack_a->size - pos_a))
		moves_a = (data->stack_a->size - pos_a) * -1;
	else
		moves_a = pos_a;
	if (pos_b > (data->stack_b->size - pos_b))
		moves_b = (data->stack_b->size - pos_b) * -1;
	else
		moves_b = pos_b;
	if (controller == 1)
		return (moves_b);
	else
		return (moves_a);
}

// Función para calcular el total de los movimientos
// de los elementos en ambas pilas por la fuquinorminete
int	next_move_2(int moves_a, int moves_b)
{
	if (moves_a >= 0 && moves_b >= 0)
	{
		if (moves_a > moves_b)
			return (moves_a);
		else
			return (moves_b);
	}
	else
	{
		if (moves_a > moves_b)
			return (moves_b * -1);
		else
			return (moves_a * -1);
	}
}

// Función para calcular el total de los movimientos
// de los elementos en la pila B para pasar a la pila A
int	next_move(t_Data *data, int value_to_find)
{
	int	moves_a;
	int	moves_b;

	moves_a = moves(data, value_to_find, 0);
	moves_b = moves(data, value_to_find, 1);
	if (moves_a >= 0 && moves_b >= 0)
		return (next_move_2(moves_a, moves_b));
	else if (moves_a <= 0 && moves_b <= 0)
		return (next_move_2(moves_a, moves_b));
	else
	{
		if (moves_a < 0)
			return ((moves_a * -1) + moves_b);
		else if (moves_b < 0)
			return ((moves_b * -1) + moves_a);
	}
	return (-1);
}

// Función para calcular cual es el elemento con menos movimientos
void	calcutate_moves(t_Data *data)
{
	t_Node	*current;
	t_Node	*proximate;

	current = data->stack_b->top;
	proximate = data->stack_b->top;
	while (current != NULL)
	{
		while (proximate != NULL)
		{
			if (next_move(data, current->data)
				<= next_move(data, proximate->data))
				proximate = proximate->next;
			else
				break ;
		}
		if (proximate == NULL)
		{			
			data->count_a = moves(data, current->data, 0);
			data->count_b = moves(data, current->data, 1);
			return ;
		}
		current = current->next;
	}
}

// Función para ordenar pilas de 3 o menos
void	sort_small(t_Data *data)
{
	if (data->stack_a->size == 1)
		free_stack(data->stack_a);
	else if (data->stack_a->size == 2 && !is_sorted_stack(data))
		sa(data);
	else if (data->stack_a->size == 3)
	{
		while (!is_sorted_stack(data))
		{
			if (find_pos(data->stack_a->top,
					max_stack(data->stack_a->top)) == 0)
				ra(data);
			else if (find_pos(data->stack_a->top,
					max_stack(data->stack_a->top)) == 1)
				rra(data);
			else if (find_pos(data->stack_a->top,
					max_stack(data->stack_a->top)) == 2)
				sa(data);
		}
	}
}
