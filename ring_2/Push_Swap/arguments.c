/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:28:49 by yoropeza          #+#    #+#             */
/*   Updated: 2023/06/13 11:10:30 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función si el argumento viene entre comillas
int	pharse_arguments(char *str, int *stack_a, int *len)
{
	int		i;
	int		j;
	int		valid;
	char	**number;

	valid = 1;
	number = ft_split(str, ' ');
	if (!number[0])
		return (0);
	i = -1;
	while (number[++i])
	{		
		if (has_dupe(stack_a, ft_atoil(number[i])))
			valid = 0;
		j = -1;
		while (number[i][++j])
			if (!ft_isdigit(number[i][j]))
				valid = 0;
		stack_a[*len] = ft_atoi(number[i]);
		*len += 1;
	}
	free(number);
	return (valid);
}

// Función para validar los argumentos pasados desde la línea de comandos
// Devuelve 1 si los argumentos son válidos, en caso contrario devuelve 0
int	is_valid_arguments(char **argv, int *stack_a, int *len)
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
				valid = -1;
			else if (!ft_isdigit(argv[i][j]))
				valid = 0;
		}
		if (valid == -1)
			valid = pharse_arguments(argv[i], stack_a, len);
		else if (valid)
		{	
			if (has_dupe(stack_a, ft_atoil(argv[i])))
				valid = 0;
			stack_a[*len] = ft_atoi(argv[i]);
			*len += 1;
		}
	}	
	stack_a[*len] = '\0';
	return (valid);
}
