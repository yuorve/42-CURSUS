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

// Función para calcular los movimientos necesarios para llevar un elemento a la otra pila
int		Moves(t_Data *data, int valueToFind, int controller)
{
	int	pos_a;
	int pos_b;
	int moves_a;
	int moves_b;
	
	pos_a = findPos(data->stack_a->top, findNext(data, valueToFind));
	pos_b = findPos(data->stack_b->top, valueToFind);	
	if (pos_a > (data->stack_a->size - pos_a))
		moves_a = (data->stack_a->size - pos_a) * -1;		
	else
		moves_a = pos_a;
	if (pos_b > (data->stack_b->size - pos_b))
		moves_b = (data->stack_b->size - pos_b) * -1;
	else
		moves_b = pos_b;
	if (controller == 1)
		return moves_b;
	else
		return moves_a;
}

// Función para calcular el total de los movimientos de los elementos en la pila B para pasar a la pila A
int		NextMove(t_Data *data, int valueToFind)
{
	int moves_a;
	int moves_b;
	
	moves_a = Moves(data, valueToFind, 0);
	moves_b = Moves(data, valueToFind, 1);
	if (moves_a >= 0 && moves_b >= 0)
	{
		if (moves_a > moves_b)
			return moves_a;
		else
			return moves_b;
	}
	else if (moves_a <= 0 && moves_b <= 0)
	{
		if (moves_a > moves_b)
			return (moves_b * -1);
		else
			return (moves_a * -1);
	}
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
void		calcutateMoves(t_Data *data)
{
	t_Node *current;
	t_Node *proximate;

	current = data->stack_b->top;
	proximate = data->stack_b->top;
	while (current != NULL)
	{
		while (proximate != NULL)
		{
			if (NextMove(data, current->data) <= NextMove(data, proximate->data))
				proximate = proximate->next;
			else
				break ;			
		}
		if (proximate == NULL)
		{			
			data->count_a = Moves(data, current->data, 0);
			data->count_b = Moves(data, current->data, 1);
			return ;
		}
        current = current->next;
	}
}
