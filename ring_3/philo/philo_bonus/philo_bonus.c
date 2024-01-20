/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:42:10 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:37:24 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	table(int philosopher_id, t_data *data)
{
	time_t	time;

	time = get_time_in_ms();
	if (get_time_in_ms() - data->time_remaining[philosopher_id]
		> data->time_to_die)
	{
		data->dead[philosopher_id] = 1;
		data->game_over = 1;
		printf("%ld %d is dead\n", time, philosopher_id);
		exit(2);
	}
	printf("%ld %d is thinking\n", time, philosopher_id);
	sem_wait(data->forks);
	printf("%ld %d has taken a pair of forks\n", time, philosopher_id);
	printf("%ld %d is eating\n", time, philosopher_id);
	usleep(data->time_to_eat * 1000);
	sem_post(data->forks);
	data->time_remaining[philosopher_id] = get_time_in_ms();
	data->meals[philosopher_id]++;
	if (data->meals[philosopher_id] >= data->numbers_of_meals)
		exit(3);
	printf("%ld %d is sleeping\n", time, philosopher_id);
	usleep(data->time_to_sleep * 1000);
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
			0644, (data->num_of_philos / 2));
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
