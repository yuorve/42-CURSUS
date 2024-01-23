/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:30:00 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/23 20:48:22 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_dead(t_data *data, int philosopher_id)
{
	if (get_time_in_ms() - data->time_remaining[philosopher_id]
		>= data->time_to_die)
	{
		data->dead[philosopher_id] = 1;
		data->game_over = 1;
		printf("%ldms %d died\n", elapsed(data), philosopher_id + 1);
		exit (2);
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
