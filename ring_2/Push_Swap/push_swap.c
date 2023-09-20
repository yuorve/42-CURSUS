/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:50:32 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/13 16:01:08 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ATOI para un valor int long
long	ft_atoil(const char *str)
{
	int		i;
	long	number;
	long	negative;

	i = 0;
	number = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (str[i] - '0');
		str++;
	}
	return (number * negative);
}

// Función para ordenar la pila en orden ascendente 
// Utilizando el algoritmo de selección
void	sort_stack(t_Data *data)
{
	t_Stack	*sorted_stack;
	t_Stack	*temp_stack;
	t_Node	*current;
	int		min;

	sorted_stack = create_stack();
	temp_stack = create_stack();
	current = data->stack_a->top;
	while (current != NULL)
	{
		push(temp_stack, current->data);
		current = current->next;
	}
	while (!is_empty(temp_stack))
	{
		min = pop(temp_stack);
		while (!is_empty(sorted_stack) && peek(sorted_stack) < min)
		{
			push(temp_stack, pop(sorted_stack));
		}
		push(sorted_stack, min);
	}
	data->tmp = sorted_stack;
	free_stack(temp_stack);
}

void	ft_void(void)
{
	system("leaks -q 'push_swap'");
}

// Push_Swap 42
int	main(int argc, char **argv)
{
	t_Data	data;

	atexit(ft_void);
	if (argc == 1)
		return (0);
	else if (argc > 1)
	{
		ft_bzero(&data, sizeof(data));
		check_arguments(&data, argv, argc);
		sort_stack(&data);
		if (!is_sorted_stack(&data) && data.stack_a->size <= 3)
			sort_small(&data);
		else if (!is_sorted_stack(&data))
			sort(&data);
	}	
	free_stack(data.tmp);
	free_stack(data.stack_a);
	return (0);
}
