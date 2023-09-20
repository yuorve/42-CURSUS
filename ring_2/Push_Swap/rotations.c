/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 07:08:00 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/14 07:18:46 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para desplazar la pila A hacia arriba
void	ra(t_Data *data)
{
	t_Node	*current;
	t_Node	*new_last;

	current = data->stack_a->top;
	new_last = data->stack_a->top;
	if (data->stack_a->size < 2)
		return ;
	data->stack_a->top = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = new_last;
	new_last->next = NULL;
	ft_printf("ra\n");
}

// Función para desplazar la pila B hacia arriba
void	rb(t_Data *data)
{
	t_Node	*current;
	t_Node	*new_last;

	current = data->stack_b->top;
	new_last = data->stack_b->top;
	if (data->stack_b->size < 2)
		return ;
	data->stack_b->top = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = new_last;
	new_last->next = NULL;
	ft_printf("rb\n");
}

// Función para desplazar ambas pilaa hacia arriba
void	rr(t_Data *data)
{
	t_Node	*current;
	t_Node	*new_last;

	current = data->stack_a->top;
	new_last = data->stack_a->top;
	if (data->stack_a->size < 2 || data->stack_b->size < 2)
		return ;
	data->stack_a->top = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = new_last;
	new_last->next = NULL;
	current = data->stack_b->top;
	new_last = data->stack_b->top;
	data->stack_b->top = current->next;
	while (current->next != NULL)
		current = current->next;
	current->next = new_last;
	new_last->next = NULL;
	ft_printf("rr\n");
}
