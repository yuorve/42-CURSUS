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

// Función para ordenar la pila en orden ascendente utilizando el algoritmo de selección
void sortStack(t_Data *data) {
    t_Stack *sortedStack;
    t_Stack *tempStack;
	t_Node *current;
    
	sortedStack = createStack();
	tempStack = createStack();
    current = data->stack_a->top;
    while (current != NULL) {
        push(tempStack, current->data);
        current = current->next;
    }
    while (!isEmpty(tempStack)) {
        int min = pop(tempStack);
        while (!isEmpty(sortedStack) && peek(sortedStack) < min) {
            push(tempStack, pop(sortedStack));
        }
        push(sortedStack, min);
    }
	data->tmp = sortedStack;
    freeStack(tempStack);
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
		sortStack(&data);
		if (!isSortedStack(&data) && data.stack_a->size <= 3)
			sort_small(&data);
		else if (!isSortedStack(&data))
			sort(&data);
	}
	return (0);
}
