/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoropeza <yoropeza@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:31:23 by yoropeza          #+#    #+#             */
/*   Updated: 2024/01/22 19:35:10 by yoropeza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*philos;
	int				*meals;
	int				*dead;
	int				philos_id;	
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				numbers_of_meals;
	int				game_over;
	time_t			start_time;
	time_t			*time_remaining;
}	t_data;

void	ft_init(t_data *data);
void	ft_free(t_data *data);
void	ft_bzero(void *s, size_t n);
void	err_msg(int errno);
void	validate(t_data *data);
void	do_action(int philo_id, int left_fork, int right_fork, t_data *data);
void	do_eat(t_data *data, int philosopher_id);
void	do_sleep(t_data *data, int philosopher_id);
void	just_one(t_data *data);
int		ft_atoi(const char *str);
time_t	get_time_in_ms(void);
time_t	elapsed(t_data *data);
#endif
