/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/14 07:17:26 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para empujar un elemento en la pila
void push(t_Stack *stack, int data)
{
	t_Node	*newNode;

	newNode = (t_Node *)malloc(sizeof(t_Node));
	newNode->data = data;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->size++;
}

// Función para sacar un elemento de la pila
int pop(t_Stack * stack)
{
	t_Node	*temp;

	if (isEmpty(stack))
	{
		printf("La pila está vacía.\n");
		exit(1);
	}
	temp = stack->top;
	int data = temp->data;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return data;
}

// Función para mover un elemento de la pila B a la A
void pa(t_Data *data)
{
	if (isEmpty(data->stack_b))
		return;
	push(data->stack_a, pop(data->stack_b));
	ft_printf("pa\n");
}

// Función para mover un elemento de la pila A a la B
void pb(t_Data *data)
{
	if (isEmpty(data->stack_a))
		return;
	push(data->stack_b, pop(data->stack_a));
	ft_printf("pb\n");
}
