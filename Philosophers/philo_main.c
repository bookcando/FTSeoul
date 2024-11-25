/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:02:39 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 15:42:26 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main_thread_create(t_philosopher **philosophers, t_common **common, \
	pthread_t **threads, pthread_mutex_t **mutex_forks)
{
	int	index;

	index = 0;
	while (index < (*common)->number_of_philosophers)
	{
		if (pthread_create(&(*threads)[index], 0, \
			philosopher_thread, &((*philosophers)[index])))
		{
			printf("error on making thread, thread index : %d\n", index);
			(*common)->dying_message = 1;
			pthread_mutex_unlock(&(*common)->mutex_start);
			index--;
			while (index >= 0)
				pthread_join((*threads)[index--], 0);
			free((*threads));
			free((*mutex_forks));
			free((*philosophers));
			free((*common));
			return (0);
		}
		index++;
	}
	return (1);
}

void	main_thread_timeset(t_philosopher **philosophers, t_common **common)
{
	int		index;
	size_t	time;

	time = ml_gettime();
	index = 0;
	while (index < (*common)->number_of_philosophers)
	{
		(*philosophers)[index].last_eat = time;
		index++;
	}
	(*common)->time_begin = time;
}

void	main_clean(t_philosopher **philosophers, t_common **common, \
	pthread_t **threads, pthread_mutex_t **mutex_forks)
{
	int	index;

	index = 0;
	while (index < (*common)->number_of_philosophers)
	{
		pthread_join((*threads)[index], 0);
		index++;
	}
	free((*threads));
	free((*mutex_forks));
	free((*philosophers));
	free((*common));
}

int	main_thread_check(t_philosopher **philosophers, t_common **common, \
	pthread_t **threads, pthread_mutex_t **mutex_forks)
{
	(*threads) = (pthread_t *)malloc(sizeof(pthread_t) * \
		(*common)->number_of_philosophers);
	if ((*threads) == 0)
	{
		free(*philosophers);
		free(*common);
		free(*mutex_forks);
		free((*threads));
		printf("Memory Allocation Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philosopher	*philosophers;
	t_common		*common;
	pthread_t		*threads;
	pthread_mutex_t	*mutex_forks;

	philosophers = 0;
	common = 0;
	mutex_forks = 0;
	if (argc != 6 && argc != 5)
		return (printf("invalid amount of arguments\n"));
	if (main_init(argv, &common, &philosophers, &mutex_forks))
		return (1);
	if (main_thread_check(&philosophers, &common, &threads, &mutex_forks))
		return (1);
	pthread_mutex_lock(&common->mutex_start);
	if (main_thread_create(&philosophers, &common, &threads, &mutex_forks) == 0)
		return (0);
	usleep(1000);
	main_thread_timeset(&philosophers, &common);
	pthread_mutex_unlock(&common->mutex_start);
	monitoring(philosophers, common);
	main_clean(&philosophers, &common, &threads, &mutex_forks);
}
