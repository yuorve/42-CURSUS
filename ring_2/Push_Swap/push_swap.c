/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:32 by yoropeza          #+#    #+#             */
/*   Updated: 2023/06/12 15:10:49 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para validar los argumentos pasados desde la línea de comandos
// Devuelve 1 si los argumentos son válidos, en caso contrario devuelve 0
int	is_valid_arguments_old(char **argv, int *stack_a)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	valid = 1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
				valid = 0;
			if (!ft_isdigit(argv[i][j]))
				valid = 0;
		}
		if (valid)
		{	
			if (has_dupe(stack_a, ft_atoil(argv[i])))
				valid = 0;
			stack_a[i - 1] = ft_atoi(argv[i]);
		}
	}
	stack_a[i - 1] = '\0';
	return (valid);
}

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

// Comprobar que los argumentos son válidos
// Comprobar que no está ordenado ya
int	main(int argc, char **argv)
{
	int	len;
	int	*stack_a;
	int	*stack_b;

	if (argc == 1)
		return (0);
	if (argc < 2)
		return (ft_printf("Error\n"));
	stack_a = malloc (argc * sizeof(int));
	stack_b = malloc (argc * sizeof(int));
	len = 0;
	if (!is_valid_arguments(argv, stack_a, &len))
	{
		free(stack_a);
		free(stack_b);
		return (ft_printf("Error\n"));
	}
	if (is_sorted(stack_a, len, 0))
	{
		free(stack_a);
		free(stack_b);
		return (0);
	}
	router(stack_a, stack_b, len);
	free(stack_a);
	free(stack_b);
	return (0);
}
