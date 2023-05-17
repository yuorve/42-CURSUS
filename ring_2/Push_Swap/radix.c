/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:18:46 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 20:03:43 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para ordenar por las unidades/decenas/...
// Se utiliza para ordenar el algoritmo Radix Sort
void countSort(int *stack_a, int n, int exp, int *output, int *count) {
	int i;
	 
	i = 0;
	while (i < n) {
		int index = stack_a[i++] / exp;
		count[index % 10]++;
	}
	i = 1;
	while (i < 10) {
		count[i] += count[i - 1];
		i++;
	}
	i = n - 1;
	while (i >= 0) {
		int index = stack_a[i] / exp;
		output[count[index % 10] - 1] = stack_a[i];
		count[index % 10]--;
		i--;
	}
	i = 0;
	while (i < n) {
		stack_a[i] = output[i];
		i++;
	}
}

// Función para ordenar los argumentos pasados desde la línea de comandos
// Utiliza el algoritmo Radix Sort
void radixSort(int *stack_a, int n) {
    int *output;
	int *count;
	int max;
	int i;
	int exp;

    output = malloc(n * sizeof(int*));
	count = malloc(10 * sizeof(int*));
    max = stack_a[0];
	i = 0;
	while (++i < n) {
        if (stack_a[i] > max) {
            max = stack_a[i];
        }
    }
	exp = 1;
	while (max / exp > 0) {
		i = 0;
		while(i < 10)
			count[i++] = 0;
        countSort(stack_a, n, exp, output, count);
		exp *= 10;
    }
	free(count);
	free(output);
}
