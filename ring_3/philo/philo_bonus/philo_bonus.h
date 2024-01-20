/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:31:23 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/20 18:39:27 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <semaphore.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef struct s_data
{
	sem_t	*forks;
	pid_t	*philos;
	int		*meals;
	int		*dead;
	int		sem_id;
	int		philos_id;	
	int		num_of_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		numbers_of_meals;
	int		game_over;
	int		res;
	time_t	start_time;
	time_t	*time_remaining;
}	t_data;

void	ft_init(t_data *data);
void	ft_free(t_data *data);
void	ft_bzero(void *s, size_t n);
void	err_msg(int err_no);
void	validate(t_data *data);
void	*routine(void *arg);
void	do_action(int i, int j, int status, t_data *data);
int		ft_atoi(const char *str);
time_t	get_time_in_ms(void);
#endif
