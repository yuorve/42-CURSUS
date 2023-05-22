/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:45:25 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/22 10:31:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/inc/libft.h"

int stack_size(int *stack);
int has_dupe(int *stack, int n);

void push(int *stack_a, int *stack_b, char c, int size);
void swap(int *stack, char c);
void rotate(int *stack, int size, char c);
void rev_rotate(int *stack, int size, char c);
void sort_small(int *stack_a, int size);
void sort_small_2(int *stack_a, int size);
void sort_small_3(int *stack_a, int size);
void sort_large(int *stack_a, int *stack_b, int size);
void count_sort(int *stack_a, int n, int exp, int *output);
void radix_sort(int *stack_a, int n);

int	sorting(int *stack_a, int *stack_b, int *stack_tmp, int size);
int is_valid_arguments(char **argv, int *stack_a);
int is_sorted(int *stack_a, int size);
void router(int *stack_a, int *stack_b, int size);

#endif
