/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:20:02 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/23 19:48:35 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_dead(t_data *data, int philosopher_id)
{
	if (get_time_in_ms() - data->time_remaining[philosopher_id]
		>= data->time_to_die)
	{
		data->dead[philosopher_id] = 1;
		data->game_over = 1;
		printf("%ldms %d died\n", elapsed(data), philosopher_id + 1);
		exit (1);
	}
}

void	do_eat(t_data *data, int philosopher_id)
{
	time_t	time;

	time = get_time_in_ms();
	while (get_time_in_ms() - time < data->time_to_eat)
	{
		check_dead(data, philosopher_id);
		usleep(500);
	}
}

void	do_sleep(t_data *data, int philosopher_id)
{
	time_t	time;

	time = get_time_in_ms();
	while (get_time_in_ms() - time < data->time_to_sleep)
	{
		check_dead(data, philosopher_id);
		usleep(500);
	}
}

void	just_one(t_data *data)
{
	if (data->num_of_philos == 1)
	{
		usleep(data->time_to_die * 1000);
		printf("%ldms 1 died\n", elapsed(data));
		exit (1);
	}
}

void	do_action(int philo_id, int left_fork, int right_fork, t_data *data)
{
	check_dead(data, philo_id);
	printf("%ldms %d is thinking\n", elapsed(data), philo_id + 1);
	pthread_mutex_lock(&data->forks[left_fork]);
	check_dead(data, philo_id);
	printf("%ldms %d has taken a fork\n", elapsed(data), philo_id + 1);
	pthread_mutex_lock(&data->forks[right_fork]);
	check_dead(data, philo_id);
	printf("%ldms %d has taken a fork\n", elapsed(data), philo_id + 1);
	printf("%ldms %d is eating\n", elapsed(data), philo_id + 1);
	data->time_remaining[philo_id] = get_time_in_ms();
	do_eat(data, philo_id);
	data->meals[philo_id]++;
	pthread_mutex_unlock(&data->forks[left_fork]);
	pthread_mutex_unlock(&data->forks[right_fork]);
}
