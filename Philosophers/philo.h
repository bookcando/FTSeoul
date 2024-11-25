/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:07:20 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 15:41:11 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_common
{
	int					number_of_philosophers;
	ssize_t				time_to_die;
	ssize_t				time_to_eat;
	ssize_t				time_to_sleep;
	ssize_t				times_must_eat;
	size_t				time_begin;
	int					dying_message;
	pthread_mutex_t		mutex_print;
	pthread_mutex_t		mutex_start;
	pthread_mutex_t		mutex_done;
	int					done;
}	t_common;

typedef struct s_philosopher
{
	int					me;
	pthread_mutex_t		*mutex_left_fork;
	pthread_mutex_t		*mutex_right_fork;
	size_t				last_eat;
	pthread_mutex_t		mutex_times_left;
	int					times_left;
	struct s_common		*common_data;
}	t_philosopher;

int		main_init(char **argv, t_common **common, \
	t_philosopher **philosophers,	pthread_mutex_t **mutex_forks);
int		monitoring(t_philosopher *philosopher, t_common *common);
int		person_eat_rl(t_philosopher *person, t_common *common);
int		person_eat_lr(t_philosopher *person, t_common *common);
ssize_t	ft_atoi(const char *str);

int		person_print(t_philosopher *person, t_common *common, char *string);
size_t	ml_gettime(void);
void	ml_sleep(size_t	utime);
int		cadaver_check_in_mutex(t_common *common);
int		cadaver_check(t_common *common);
int		philosopher_run(t_philosopher **person, \
	t_common **common, int *must_eat);
void	*philosopher_thread(void *arg);

#endif