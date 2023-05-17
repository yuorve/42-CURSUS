/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:45:25 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 17:38:56 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/inc/libft.h"

int		stack_size(int *stack);
int		hasDupe(int *stack, int n);

void push(int *stack_a, int *stack_b, char c, int size);
void swap(int *stack, char c);
void rotate(int *stack, int size, char c);
void sort_small(int *stack_a, int size);
void sort_large(int *stack_a, int *stack_b, int size);
void countSort(int *stack_a, int n, int exp, int *output, int *count);
void radixSort(int *stack_a, int n);

int is_valid_arguments(char **argv, int *stack_a);
int is_sorted(int *stack_a, int size);
void router(int *stack_a, int *stack_b, int size);

#endif
