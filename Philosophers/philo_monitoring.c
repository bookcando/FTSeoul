/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:09:14 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 16:04:11 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitoring_musteat_done(t_common **common, int *index, int last)
{
	if ((*index) == last)
	{
		pthread_mutex_lock(&(*common)->mutex_done);
		if ((*common)->done == last)
		{
			pthread_mutex_unlock(&(*common)->mutex_done);
			return (1);
		}
		pthread_mutex_unlock(&(*common)->mutex_done);
		(*index) = 0;
		usleep(100);
	}
	return (0);
}

int	monitoring_pass_musteat_done(t_philosopher **philosopher, \
	t_common **common, int *index)
{
	if ((*common)->times_must_eat != -1)
	{
		pthread_mutex_lock(&(*philosopher)[(*index)].mutex_times_left);
		if ((*philosopher)[(*index)].times_left == 0)
		{
			pthread_mutex_unlock(&(*philosopher)[(*index)].mutex_times_left);
			(*index)++;
			return (1);
		}
		pthread_mutex_unlock(&(*philosopher)[(*index)].mutex_times_left);
	}
	return (0);
}

int	monitoring_time(t_philosopher **philosopher, t_common **common, \
	int *index, size_t time_to_die)
{
	size_t	time_death;

	pthread_mutex_lock(&(*common)->mutex_print);
	time_death = ml_gettime();
	if ((*philosopher)[(*index)].last_eat + time_to_die <= time_death)
	{
		if ((*common)->dying_message == 0)
		{
			printf("%zu %d died\n", (time_death - (*common)->time_begin) \
				/ 1000, (*index) + 1);
		}
		if ((*common)->number_of_philosophers == 1)
			pthread_mutex_unlock((*philosopher)[(*index)].mutex_left_fork);
		(*common)->dying_message = 1;
		pthread_mutex_unlock(&(*common)->mutex_print);
		return (1);
	}
	pthread_mutex_unlock(&(*common)->mutex_print);
	return (0);
}

int	monitoring(t_philosopher *philosopher, t_common *common)
{
	int		index;
	int		last;
	size_t	time_to_die;

	index = 0;
	last = common->number_of_philosophers;
	time_to_die = common->time_to_die;
	while (1)
	{
		if (monitoring_musteat_done(&common, &index, last))
			return (0);
		if (monitoring_pass_musteat_done(&philosopher, &common, &index))
			continue ;
		if (monitoring_time(&philosopher, &common, &index, time_to_die))
			return (0);
		index++;
	}
	return (0);
}
