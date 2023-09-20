/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:23:57 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/13 12:09:34 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para encontrar la posición de un valor en la lista enlazada
int	find_pos(t_Node *head, int value_to_find)
{
	int		position;
	t_Node	*current;

	current = head;
	position = 0;
	while (current != NULL)
	{
		if (current->data == value_to_find)
		{
			return (position);
		}
		current = current->next;
		position++;
	}
	return (-1);
}

// Función para encontrar el valor correlativo en la pila A
int	find_next(t_Data *data, int value_to_find)
{
	int		position;
	int		number;
	t_Node	*current;

	position = 0;
	number = 0;
	current = data->stack_a->top;
	if (value_to_find > max_stack(data->stack_a->top))
		return (min_stack(data->stack_a->top));
	number = max_stack(data->stack_a->top);
	position = find_pos(data->tmp->top, max_stack(data->stack_a->top));
	while (current != NULL)
	{
		if (find_pos(data->tmp->top, current->data)
			> find_pos(data->tmp->top, value_to_find)
			&& find_pos(data->tmp->top, current->data) < position)
		{
			position = find_pos(data->tmp->top, current->data);
			number = current->data;
		}
		current = current->next;
	}
	return (number);
}

// Función para buscar el menor elemento de la pila
int	min_stack(t_Node *top)
{
	int		i;
	t_Node	*current;

	current = top;
	i = INT_MAX;
	while (current != NULL)
	{
		if (current->data < i)
			i = current->data;
		current = current->next;
	}
	return (i);
}

// Función para buscar el mayor elemento de la pila
int	max_stack(t_Node *top)
{
	int		i;
	t_Node	*current;

	current = top;
	i = 0;
	while (current != NULL)
	{
		if (current->data > i)
			i = current->data;
		current = current->next;
	}
	return (i);
}

// Función para comprobar si está ordenada la pila
int	is_sorted_stack(t_Data *data)
{	
	t_Node	*current;

	current = data->stack_a->top;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
