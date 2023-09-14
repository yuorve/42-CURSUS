/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:16:08 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/14 08:24:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para crear una nueva pila vacía
t_Stack	*createStack()
{
	t_Stack *stack;

	stack = (t_Stack *)malloc(sizeof(t_Stack));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

// Función para verificar si la pila está vacía
int	isEmpty(t_Stack * stack)
{
	return (stack->top == NULL);
}

// Función para obtener el valor en la parte superior de la pila sin quitarlo
int	peek(t_Stack * stack)
{
	if (isEmpty(stack)) {
		printf("La pila está vacía.\n");
		exit(1);
	}
	return stack->top->data;
}

// Función para obtener el valor en la parte inferior de la pila sin quitarlo
int	pook(t_Stack * stack)
{
	t_Node* current;

	if (isEmpty(stack)) {
		printf("La pila está vacía.\n");
		exit(1);
	}
	current = stack->top;
	while (current->next != NULL)
		current = current->next;
	return current->data;
}

// Función para liberar la memoria de la pila
void	freeStack(t_Stack *stack)
{
	while (!isEmpty(stack))
		pop(stack);
	free(stack);
}
