/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:42:10 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/22 19:38:09 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	table(int philosopher_id, t_data *data)
{
	if (get_time_in_ms() - data->time_remaining[philosopher_id]
		>= data->time_to_die)
	{
		data->dead[philosopher_id] = 1;
		data->game_over = 1;
		printf("%ldms %d died\n", elapsed(data), philosopher_id + 1);
		exit(2);
	}
	printf("%ldms %d is thinking\n", elapsed(data), philosopher_id + 1);
	sem_wait(data->forks);
	printf("%ldms %d has taken a fork\n", elapsed(data), philosopher_id + 1);
	just_one(data);
	sem_wait(data->forks);
	printf("%ldms %d has taken a fork\n", elapsed(data), philosopher_id + 1);
	printf("%ldms %d is eating\n", elapsed(data), philosopher_id + 1);
	data->time_remaining[philosopher_id] = get_time_in_ms();
	do_eat(data, philosopher_id);
	sem_post(data->forks);
	sem_post(data->forks);
	data->meals[philosopher_id]++;
	if (data->meals[philosopher_id] >= data->numbers_of_meals)
		exit(3);
	printf("%ldms %d is sleeping\n", elapsed(data), philosopher_id + 1);
	do_sleep(data, philosopher_id);
	return (0);
}

void	*routine(void *arg)
{
	t_data	*data;
	int		philosopher_id;

	data = (t_data *)arg;
	philosopher_id = data->philos_id;
	data->meals[data->philos_id] = 0;
	data->time_remaining[data->philos_id] = get_time_in_ms();
	while (!data->game_over)
	{
		if (table(philosopher_id, data))
			break ;
	}
	exit (4);
	return (NULL);
}

void	philosopher(t_data *data)
{
	int	i;
	int	j;
	int	status;

	sem_unlink("/forks");
	data->forks = sem_open("/forks", O_CREAT | O_EXCL,
			0644, (data->num_of_philos));
	if (data->forks == SEM_FAILED)
	{
		printf("sem_open() failed.  errno:%d\n", errno);
		exit(EXIT_FAILURE);
	}
	i = -1;
	j = -1;
	status = 0;
	do_action(i, j, status, data);
	sem_close(data->forks);
	sem_unlink("/forks");
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
