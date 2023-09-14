/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:16:56 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/14 07:18:19 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para intercambiar el primer elemento de la pila A con el segundo
void sa(t_Data *data)
{
	t_Node *aux;

	if (data->stack_a->size < 2)
		return ;
	aux = data->stack_a->top;
	data->stack_a->top = data->stack_a->top->next;
	aux->next = data->stack_a->top->next;
	data->stack_a->top->next = aux;
	ft_printf("sa\n");
}

// Función para intercambiar el primer elemento de la pila B con el segundo
void sb(t_Data *data)
{
	t_Node *aux;

	if (data->stack_b->size < 2)
		return ;
	aux = data->stack_b->top;
	data->stack_b->top = data->stack_b->top->next;
	aux->next = data->stack_b->top->next;
	data->stack_b->top->next = aux;
	ft_printf("sb\n");
}

// Función para intercambiar los primeros y segundos elementos de la pila A y B
void ss(t_Data *data)
{
	t_Node *aux;

	if (data->stack_a->size < 2
		&& data->stack_b->size < 2)
		return ;
	aux = data->stack_a->top;
	data->stack_a->top = data->stack_a->top->next;
	aux->next = data->stack_a->top->next;
	data->stack_a->top->next = aux;
	aux = data->stack_b->top;
	data->stack_b->top = data->stack_b->top->next;
	aux->next = data->stack_b->top->next;
	data->stack_b->top->next = aux;
	ft_printf("ss\n");
}
