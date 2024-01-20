/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:56:32 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:26:56 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_msg(int errno)
{
	if (errno == 1)
		printf("Philosophers nedeed.\n");
	else if (errno == 2)
		printf("Time to die nedeed.\n");
	else if (errno == 3)
		printf("Time to eat nedeed.\n");
	else if (errno == 4)
		printf("Time to sleep nedeed.\n");
	else if (errno == 5)
		printf("Wrong number of meals.\n");
}

void	validate(t_data *data)
{
	int	errno;

	errno = 0;
	if (data->num_of_philos < 1)
		errno = 1;
	else if (data->time_to_die < 1)
		errno = 2;
	else if (data->time_to_eat < 1)
		errno = 3;
	else if (data->time_to_sleep < 1)
		errno = 4;
	else if (data->numbers_of_meals < 1)
		errno = 5;
	if (errno > 0)
	{
		err_msg(errno);
		exit (EXIT_FAILURE);
	}
}
