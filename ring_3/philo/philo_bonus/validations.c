/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:56:32 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:38:14 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	err_msg(int err_no)
{
	if (err_no == 1)
		printf("Philosophers nedeed.\n");
	else if (err_no == 2)
		printf("Time to die nedeed.\n");
	else if (err_no == 3)
		printf("Time to eat nedeed.\n");
	else if (err_no == 4)
		printf("Time to sleep nedeed.\n");
	else if (err_no == 5)
		printf("Wrong number of meals.\n");
}

void	validate(t_data *data)
{
	int	err_no;

	err_no = 0;
	if (data->num_of_philos < 1)
		err_no = 1;
	else if (data->time_to_die < 1)
		err_no = 2;
	else if (data->time_to_eat < 1)
		err_no = 3;
	else if (data->time_to_sleep < 1)
		err_no = 4;
	else if (data->numbers_of_meals < 1)
		err_no = 5;
	if (err_no > 0)
	{
		err_msg(err_no);
		exit (EXIT_FAILURE);
	}
}
