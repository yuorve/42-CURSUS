/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:45:25 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/12 16:44:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/inc/libft.h"
# include <stdio.h>
# define INT_MIN -2147483648
# define INT_MAX 2147483647

// Estructura de un nodo en la pila
typedef struct s_Node {
	int				data;
	struct	s_Node 	*next;
}			t_Node;

// Estructura de la pila
typedef struct s_Stack {
	int				size;
	struct	s_Node	*top;
}			t_Stack;

// Estructura del conjunto de datos
typedef struct	s_Data {
		t_Stack	*stack_a;
		t_Stack	*stack_b;
		t_Stack	*tmp;
		int		average;
		int		count_a;
		int		count_b;
}				t_Data;

//Funciones
t_Stack		*create_stack();

void 		free_stack(t_Stack* stack);
void 		push(t_Stack* stack, int data);
void 		check_arguments(t_Data *data, char **argv, int argc);
void 		sort_stack(t_Data *data);
void		calcutate_moves(t_Data *data);
void		sort_small(t_Data *data);
void 		sort(t_Data *data);
void 		pa(t_Data *data);
void 		pb(t_Data *data);
void 		sa(t_Data *data);
void 		sb(t_Data *data);
void 		ss(t_Data *data);
void 		ra(t_Data *data);
void 		rb(t_Data *data);
void 		rr(t_Data *data);
void 		rra(t_Data *data);
void 		rrb(t_Data *data);
void 		rrr(t_Data *data);

int			is_empty(t_Stack* stack);
int			peek(t_Stack* stack);
int			pook(t_Stack* stack);
int			pop(t_Stack* stack);
int 		min_stack(t_Node *top);
int 		max_stack(t_Node *top);
int 		find_pos(t_Node * head, int valueToFind);
int 		find_next(t_Data *data, int valueToFind);
int			is_sorted_stack(t_Data *data);
int			moves(t_Data *data, int valueToFind, int controller);
int			next_move(t_Data *data, int valueToFind);

long		ft_atoil(const char *str);

#endif
