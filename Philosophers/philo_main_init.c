/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:07:33 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 15:42:34 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_init_common(char **argv, t_common **common)
{
	(*common) = (t_common *)malloc(sizeof(t_common) * 1);
	if (*common == 0)
		return (1);
	(*common)->number_of_philosophers = ft_atoi(argv[1]);
	(*common)->time_to_die = ft_atoi(argv[2]) * 1000;
	(*common)->time_to_eat = ft_atoi(argv[3]) * 1000;
	(*common)->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (argv[5])
		(*common)->times_must_eat = ft_atoi(argv[5]);
	else
		(*common)->times_must_eat = -1;
	(*common)->dying_message = 0;
	pthread_mutex_init(&(*common)->mutex_print, 0);
	pthread_mutex_init(&(*common)->mutex_start, 0);
	(*common)->done = 0;
	pthread_mutex_init(&(*common)->mutex_done, 0);
	return (0);
}

void	main_init_forks(t_common **common, pthread_mutex_t **mutex_forks)
{
	int	index;

	index = 0;
	while (index < (*common)->number_of_philosophers)
	{
		pthread_mutex_init(&((*mutex_forks))[index], 0);
		index++;
	}
}

void	main_init_philosophers(t_philosopher **philosophers, \
	t_common **common, pthread_mutex_t **mutex_forks)
{
	int	index;

	index = 0;
	while (index < (*common)->number_of_philosophers)
	{
		(*philosophers)[index].common_data = *common;
		(*philosophers)[index].last_eat = 0;
		(*philosophers)[index].mutex_left_fork = &((*mutex_forks))[index];
		(*philosophers)[index].mutex_right_fork = \
			&((*mutex_forks))[(index + 1) % (*common)->number_of_philosophers];
		(*philosophers)[index].me = index + 1;
		(*philosophers)[index].times_left = (*common)->times_must_eat;
		pthread_mutex_init(&((*philosophers)[index].mutex_times_left), 0);
		index++;
	}
}

int	main_init(char **argv, t_common **common, t_philosopher **philosophers, \
	pthread_mutex_t **mutex_forks)
{
	if (main_init_common(argv, common))
		return (printf("Memory Allocation Error\n"), 1);
	if ((argv[5] && (ft_atoi(argv[5]) < 0)) || \
	(*common)->number_of_philosophers < 1 || (*common)->time_to_die < 0 || \
	(*common)->time_to_eat < 1 || (*common)->time_to_sleep < 1)
	{
		printf("invalid arguments\n");
		free(*common);
		return (1);
	}
	(*philosophers) = (t_philosopher *)malloc(sizeof(t_philosopher) \
		* (*common)->number_of_philosophers);
	(*mutex_forks) = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
		* (*common)->number_of_philosophers);
	if (!((*philosophers) && (*mutex_forks)))
	{
		free(*philosophers);
		free(*mutex_forks);
		printf("Memory Allocation Error\n");
		return (1);
	}
	main_init_forks(common, mutex_forks);
	main_init_philosophers(philosophers, common, mutex_forks);
	return (0);
}
