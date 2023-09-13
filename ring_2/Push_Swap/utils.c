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
int findPos(t_Node * head, int valueToFind)
{
    int position;
    t_Node *current;

    current = head;
    position = 0;
    while (current != NULL) {
        if (current->data == valueToFind) {
            return position;
        }
        current = current->next;
        position++;
    }
    return (-1);
}

// Función para encontrar el valor correlativo en la pila A
int		findNext(t_Data *data, int valueToFind)
{
    int position = 0;
    int number = 0;
    t_Node *current;

    current = data->stack_a->top;
	if (valueToFind > maxStack(data->stack_a->top))
		return (minStack(data->stack_a->top));
    number = maxStack(data->stack_a->top);
    position = findPos(data->tmp->top, maxStack(data->stack_a->top));
    while (current != NULL) {        
        if (findPos(data->tmp->top, current->data) > findPos(data->tmp->top, valueToFind) && findPos(data->tmp->top, current->data) < position)
        {
            position = findPos(data->tmp->top, current->data);
            number = current->data;
        }
        current = current->next;
    }
    return (number);
}

// Función para buscar el menor elemento de la pila
int minStack(t_Node *top) 
{
	int	i;
	
    t_Node 	*current = top;
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
int maxStack(t_Node *top) 
{
	int	i;
	
    t_Node 	*current = top;
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
int isSortedStack(t_Data *data) 
{	
    t_Node 	*current = data->stack_a->top;
	
    while (current->next != NULL) 
	{
		if (current->data > current->next->data)
			return (0);
        current = current->next;
    }
	return (1);
}
