/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:26:56 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 15:29:52 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	person_print(t_philosopher *person, t_common *common, char *string)
{
	pthread_mutex_lock(&common->mutex_print);
	if (common->dying_message)
	{
		pthread_mutex_unlock(&common->mutex_print);
		return (1);
	}
	printf("%zu %d %s\n", (ml_gettime() - common->time_begin) \
		/ 1000, person->me, string);
	pthread_mutex_unlock(&common->mutex_print);
	return (0);
}

size_t	ml_gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ml_sleep(size_t	utime)
{
	size_t	start;

	start = ml_gettime();
	while (start + utime >= ml_gettime())
		usleep(250);
}

int	cadaver_check_in_mutex(t_common *common)
{
	if (common->dying_message)
		return (1);
	return (0);
}

int	cadaver_check(t_common *common)
{
	pthread_mutex_lock(&common->mutex_print);
	if (common->dying_message)
	{
		pthread_mutex_unlock(&common->mutex_print);
		return (1);
	}
	pthread_mutex_unlock(&common->mutex_print);
	return (0);
}
