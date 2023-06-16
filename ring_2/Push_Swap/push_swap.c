/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:32 by yoropeza          #+#    #+#             */
/*   Updated: 2023/06/16 15:48:35 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para comprobar si la pila_a está ordenada
int	is_sorted(int *stack_a, int size, int direction)
{
	int	i;
	int	valid;

	i = -1;
	valid = 1;
	if (direction == 0)
	{
		while (++i < (size - 1))
			if (stack_a[i] > stack_a[i + 1])
				valid = 0;
	}
	else
	{
		while (++i < (size - 1))
			if (stack_a[i] < stack_a[i + 1])
				valid = 0;
	}
	return (valid);
}

// Función para realizar el enrutamiento en función del número de argumentos
void	router(int *stack_a, int *stack_b, int size)
{	
	if (size <= 3)
		sort_small(stack_a, size);
	else
	{
		if (size > 25)
			pre_sort(stack_a, stack_b, size);
		sort_large(stack_a, stack_b, size);
	}
}

void	ft_void()
{
	system("leaks -q 'push_swap'");
}

// Comprobar que los argumentos son válidos
// Comprobar que no está ordenado ya
int	main(int argc, char **argv)
{
	int	len;
	int	*stack_a;
	int	*stack_b;

	atexit(ft_void);
	len = argc - 1;
	if (argc == 1)
		return (0);
	if (argc == 2)
		len = count_arguments(argv[1]);
	stack_a = malloc (len * sizeof(int));
	len = 0;
	if (!is_valid_arguments(argv, stack_a, &len))
		return (free(stack_a), ft_printf("Error\n"));
	if (is_sorted(stack_a, len, 0))
		return (free(stack_a), 0);
	stack_b = malloc (len * sizeof(int));
	router(stack_a, stack_b, len);
	free(stack_b);
	free(stack_a);
	return (0);
}
