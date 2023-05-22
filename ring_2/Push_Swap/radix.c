/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:18:46 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/22 14:56:49 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ordenar por las unidades/decenas/...
// Se utiliza para ordenar el algoritmo Radix Sort
void	count_sort(int *stack_a, int n, int exp, int *count)
{
	int	*output;
	int	i;
	int	index;
	
	output = malloc (n * sizeof(int));
	i = 0;
	while (i < 10)
		count[i++] = 0;
	i = 0;
	while (i < n)
	{
		index = stack_a[i++] / exp;
		count[index % 10]++;
	}
	i = 0;
	while (++i < 10)
		count[i] += count[i - 1];
	i = n;
	while (--i >= 0)
	{
		index = stack_a[i] / exp;
		output[count[index % 10] - 1] = stack_a[i];
		count[index % 10]--;
	}
	i = -1;
	while (++i < n)
		stack_a[i] = output[i];
	free(output);
}

// Función para ordenar los argumentos pasados desde la línea de comandos
// Utiliza el algoritmo Radix Sort
void	radix_sort(int *stack_a, int n)
{
	int	max;
	int	i;
	int	exp;	
	int	*count;
	
	count = malloc (10 * sizeof(int));
	max = stack_a[0];
	i = 0;
	while (++i < n)
		if (stack_a[i] > max)
			max = stack_a[i];
	exp = 1;
	while (max / exp > 0)
	{
		i = 0;
		while (i < 10)
			count[i++] = 0;
		count_sort(stack_a, n, exp, count);
		exp *= 10;
	}	
	free(count);
}
