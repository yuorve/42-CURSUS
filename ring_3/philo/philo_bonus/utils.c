/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:07:17 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:09:02 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init(t_data *data)
{
	data->forks = malloc(data->num_of_philos * sizeof(sem_t));
	data->philos = malloc(data->num_of_philos * sizeof(pid_t));
	data->meals = malloc(data->num_of_philos * sizeof(int));
	data->dead = malloc(data->num_of_philos * sizeof(int));
	data->time_remaining = malloc(data->num_of_philos * sizeof(int));
}

void	ft_free(t_data *data)
{
	free (data->philos);
	free (data->meals);
	free (data->dead);
	free (data->time_remaining);
}

void	ft_bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	negative;

	i = 0;
	number = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (str[i] - '0');
		str++;
	}
	return (number * negative);
}

time_t	get_time_in_ms(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}
