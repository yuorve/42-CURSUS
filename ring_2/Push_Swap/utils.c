/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:23:57 by yoropeza          #+#    #+#             */
/*   Updated: 2023/05/17 20:06:20 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Función para saber la longitud de la pila
int		stack_size(int *stack) {
	int i;

	i = 0;
	while (stack[i]) {
		i++;
	}
	return (i);
}

// Función para buscar duplicados dentro de la pila
// Devuelve 1 si hay duplicados 0 sino
int		hasDupe(int *stack, int n) {
	int i;
	int valid;

	i = 0;
	valid = 0;
	while (stack[i]) {
		if (stack[i] == n)
			valid = 1;
		i++;
	}
	return (valid);
}