/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 12:05:33 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/12 12:27:55 by yoropeza         ###   ########.fr       */
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
	
    if (isEmpty(stack)) {
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

// Función para desplazar la pila A hacia arriba
void ra(t_Data *data) {
	t_Node* current = data->stack_a->top;
	t_Node* newLast = data->stack_a->top;
	
    if (data->stack_a->size < 2)
        return;
    data->stack_a->top = current->next;
    while (current->next != NULL)
        current = current->next;
    current->next = newLast;
    newLast->next = NULL;
	ft_printf("ra\n");
}

// Función para desplazar la pila B hacia arriba
void rb(t_Data *data) {
	t_Node* current = data->stack_b->top;
	t_Node* newLast = data->stack_b->top;
	
    if (data->stack_b->size < 2)
        return;
    data->stack_b->top = current->next;
    while (current->next != NULL)
        current = current->next;
    current->next = newLast;
    newLast->next = NULL;
	ft_printf("rb\n");
}

// Función para desplazar ambas pilaa hacia arriba
void rr(t_Data *data) {
	t_Node* current = data->stack_a->top;
	t_Node* newLast = data->stack_a->top;
	
    if (data->stack_a->size < 2 || data->stack_b->size < 2)
        return;
    data->stack_a->top = current->next;
    while (current->next != NULL)
        current = current->next;
    current->next = newLast;
    newLast->next = NULL;    
	current = data->stack_b->top;
	newLast = data->stack_b->top;
    data->stack_b->top = current->next;
    while (current->next != NULL)
        current = current->next;
    current->next = newLast;
    newLast->next = NULL;
	ft_printf("rr\n");
}

// Función para desplazar la pila A hacia abajo
void rra(t_Data *data) {
    t_Node* current = data->stack_a->top;
    t_Node* prev = NULL;

    if (data->stack_a->size < 2)
        return;
    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }
    current->next = data->stack_a->top;
    data->stack_a->top = current;
    prev->next = NULL;
	ft_printf("rra\n");
}

// Función para desplazar la pila B hacia abajo
void rrb(t_Data *data) {
    t_Node* current = data->stack_b->top;
    t_Node* prev = NULL;

    if (data->stack_b->size < 2)
        return;
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
void rrr(t_Data *data) {
    t_Node* current = data->stack_a->top;
    t_Node* prev = NULL;
	
	if (data->stack_b->size < 2 || data->stack_a->size < 2)
        return;
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
