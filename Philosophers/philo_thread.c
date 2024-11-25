/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:32:07 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 15:32:20 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_thread(void *arg)
{
	t_philosopher	*person;
	t_common		*common;
	int				must_eat;

	person = (t_philosopher *)arg;
	common = person->common_data;
	must_eat = common->times_must_eat;
	pthread_mutex_lock(&common->mutex_start);
	pthread_mutex_unlock(&common->mutex_start);
	if (philosopher_run(&person, &common, &must_eat))
		return (0);
	pthread_mutex_lock(&person->mutex_times_left);
	(person->times_left) = 0;
	pthread_mutex_unlock(&person->mutex_times_left);
	pthread_mutex_lock(&common->mutex_done);
	(common->done)++;
	pthread_mutex_unlock(&common->mutex_done);
	return (0);
}
