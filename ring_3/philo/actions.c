/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:20:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/21 10:23:43 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	elapsed(t_data *data)
{
	time_t	time;

	time = get_time_in_ms() - data->start_time;
	return (time);
}

void	check_dead(t_data *data, int philosopher_id)
{
	if (get_time_in_ms() - data->time_remaining[philosopher_id]
		> data->time_to_die)
	{
		data->dead[philosopher_id] = 1;
		data->game_over = 1;
		printf("%ldms %d is dead\n", elapsed(data), philosopher_id + 1);
		exit (1) ;
	}
}

void	do_action(int philo_id, int left_fork, int right_fork, t_data *data)
{
	printf("%ldms %d is thinking\n", elapsed(data), philo_id + 1);
	pthread_mutex_lock(&data->forks[left_fork]);
	printf("%ldms %d has taken a fork\n", elapsed(data), philo_id + 1);
	pthread_mutex_lock(&data->forks[right_fork]);
	printf("%ldms %d has taken a fork\n", elapsed(data), philo_id + 1);
	printf("%ldms %d is eating\n", elapsed(data), philo_id + 1);
	usleep(data->time_to_eat * 1000);
	data->time_remaining[philo_id] = get_time_in_ms();
	data->meals[philo_id]++;
	pthread_mutex_unlock(&data->forks[left_fork]);
	pthread_mutex_unlock(&data->forks[right_fork]);
}
