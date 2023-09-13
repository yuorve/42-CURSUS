/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:28:49 by yoropeza          #+#    #+#             */
/*   Updated: 2023/09/10 20:30:25 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función para validar y devolver el argumento, devuelve -1 si no es válido
int	is_valid_arguments(t_Stack *stack, char *argv)
{
	int	i;
	
	i = -1;
	while (argv[++i])
	{
		if (ft_issign(argv[i]) && !ft_isdigit(argv[i + 1]))
			return (-1);
		else if (!ft_issign(argv[i]) && (ft_isalpha(argv[i])
			|| !ft_isdigit(argv[i])))
			return (-1);
	}
	if (INT_MAX < ft_atoil(argv))
		return (-1);
	else if (INT_MIN > ft_atoil(argv))
		return (-1);
	else if (findPos(stack->top, ft_atoi(argv)) != -1)
		return (-1);
	return (0);
}

// Función si el argumento viene entre comillas
void	pharse_arguments(t_Stack *stack, char *argv)
{
	int		i;
	char	**values;

	values = ft_split(argv, ' ');
	if (!values[0])
		return (free(values));
	i = 0;
	while (values[i])
		i++;
	while (values[--i] && i > -1)
	{
		if (!is_valid_arguments(stack, values[i]))
			push(stack, ft_atoi(values[i]));
		else
		{
			freeStack(stack);
			exit(1);
		}
	}
}

//Función para comprobar los argumentos
void check_arguments(t_Data *data, char **argv, int argc)
{
	t_Stack *stack;
	int		i;

	stack = createStack();
	
	i = argc;
	while (argv[--i] && i > 0)
	{
		if (ft_strchr(argv[i],' '))
			pharse_arguments(stack, argv[i]);
		else if (!is_valid_arguments(stack, argv[i]))
			push(stack, ft_atoi(argv[i]));
		else
		{
			freeStack(stack);
			exit(1);
		}
	}
	data->stack_a = stack;
}
