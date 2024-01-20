/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:20:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:23:57 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_action(int philo_id, int left_fork, int right_fork, t_data *data)
{
	time_t	time;

	time = get_time_in_ms();
	printf("%ld %d is thinking\n", time, philo_id);
	pthread_mutex_lock(&data->forks[left_fork]);
	printf("%ld %d has taken a fork\n", time, philo_id);
	pthread_mutex_lock(&data->forks[right_fork]);
	printf("%ld %d has taken a fork\n", time, philo_id);
	printf("%ld %d is eating\n", time, philo_id);
	usleep(data->time_to_eat * 1000);
	data->time_remaining[philo_id] = get_time_in_ms();
	data->meals[philo_id]++;
	pthread_mutex_unlock(&data->forks[left_fork]);
	pthread_mutex_unlock(&data->forks[right_fork]);
}
