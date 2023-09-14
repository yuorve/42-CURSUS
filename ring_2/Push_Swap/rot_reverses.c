/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_reverses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:11:59 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/14 07:18:35 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para desplazar la pila A hacia abajo
void rra(t_Data *data)
{
	t_Node *current;
	t_Node *prev;


	current = data->stack_a->top;
	prev = NULL;
	if (data->stack_a->size < 2)
		return ;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = data->stack_a->top;
	data->stack_a->top = current;
	prev->next = NULL;
	ft_printf("rra\n");
}

// Función para desplazar la pila B hacia abajo
void rrb(t_Data *data)
{
	t_Node *current;
	t_Node *prev;

	current = data->stack_b->top;
	prev = NULL;
	if (data->stack_b->size < 2)
		return ;
	while (current->next != NULL) 
	{
		prev = current;
		current = current->next;
	}
	current->next = data->stack_b->top;
	data->stack_b->top = current;
	prev->next = NULL;
	ft_printf("rrb\n");
}

// Función para desplazar ambas pilas hacia abajo
void rrr(t_Data *data)
{
	t_Node *current;
	t_Node *prev;

	current = data->stack_a->top;
	prev = NULL;
	if (data->stack_b->size < 2 || data->stack_a->size < 2)
		return ;
	while (current->next != NULL) 
	{
		prev = current;
		current = current->next;
	}
	current->next = data->stack_a->top;
	data->stack_a->top = current;
	prev->next = NULL;
	current = data->stack_b->top;
	while (current->next != NULL) 
	{
		prev = current;
		current = current->next;
	}
	current->next = data->stack_b->top;
	data->stack_b->top = current;
	prev->next = NULL;
	ft_printf("rrr\n");
}
