/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:30:00 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/21 10:31:01 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

time_t	elapsed(t_data *data)
{
	time_t	time;

	time = get_time_in_ms() - data->start_time;
	return (time);
}

void	do_action(int i, int j, int status, t_data *data)
{
	while (++i < data->num_of_philos)
	{
		data->philos_id = i;
		data->philos[i] = fork();
		if (data->philos[i] < 0)
			exit(EXIT_FAILURE);
		else if (data->philos[i] == 0)
		{
			routine(data);
			exit(EXIT_SUCCESS);
		}
	}
	j = -1;
	i = -1;
	while (++i < data->num_of_philos)
	{
		waitpid(data->philos[i], &status, 0);
		data->res = WEXITSTATUS(status);
		if (data->res == 2)
		{
			while (++j < data->num_of_philos)
				kill(data->philos[j], 9);
			break ;
		}
	}
}
