/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:42:10 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:25:12 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checking(t_data *data)
{
	int	i;
	int	res;

	i = -1;
	res = 1;
	while (++i < data->num_of_philos)
	{
		if (data->meals[i] < data->numbers_of_meals)
			res = 0;
		if (data->dead[i] == 0)
			res = 0;
	}
	return (res);
}

void	table(int philosopher_id, int left_fork, int right_fork, t_data *data)
{
	time_t	time;

	time = get_time_in_ms();
	if (get_time_in_ms() - data->time_remaining[philosopher_id]
		> data->time_to_die)
	{
		data->dead[philosopher_id] = 1;
		data->game_over = 1;
		return (printf("%ld %d is dead\n", time, philosopher_id));
	}
	do_actions(philosopher_id, left_fork, right_fork, data);
	if (data->meals[philosopher_id] == data->numbers_of_meals)
	{
		data->game_over = 1;
		return ;
	}
	printf("%ld %d is sleeping\n", time, philosopher_id);
	usleep(data->time_to_sleep * 1000);
	return ;
}

void	*thread_routine(void *arg)
{
	t_data	*data;
	int		philosopher_id;
	int		left_fork;
	int		right_fork;

	data = (t_data *)arg;
	philosopher_id = data->philos_id;
	left_fork = data->philos_id;
	right_fork = (data->philos_id + 1) % data->num_of_philos;
	data->meals[data->philos_id] = 0;
	data->time_remaining[data->philos_id] = get_time_in_ms();
	while (!data->game_over)
	{
		table(philosopher_id, left_fork, right_fork, data);
	}
	return (NULL);
}

void	philosopher(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_init(&data->forks[i], NULL);
	i = -1;
	while (++i < data->num_of_philos)
	{
		data->philos_id = i;
		if (pthread_create(&data->philos[i], NULL, thread_routine, data) != 0)
			exit (EXIT_FAILURE);
		usleep(500);
	}
	i = -1;
	while (++i < data->num_of_philos - 1)
		pthread_join(data->philos[i], NULL);
	i = -1;
	while (++i < data->num_of_philos)
		pthread_mutex_destroy(&data->forks[i]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf("Too few or too many arguments.\n"), 0);
	ft_bzero(&data, sizeof(t_data));
	data.num_of_philos = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data.numbers_of_meals = ft_atoi(argv[5]);
	else
		data.numbers_of_meals = 999999;
	validate(&data);
	ft_init(&data);
	data.start_time = get_time_in_ms();
	philosopher(&data);
	ft_free(&data);
	return (0);
}
