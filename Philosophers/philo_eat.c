/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:20:01 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 16:06:06 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	person_eat_lr_diecheck(t_philosopher *person, t_common *common)
{
	if (cadaver_check_in_mutex(common))
	{
		pthread_mutex_unlock(&common->mutex_print);
		pthread_mutex_unlock(person->mutex_right_fork);
		pthread_mutex_unlock(person->mutex_left_fork);
		return (1);
	}
	if (person->last_eat + common->time_to_die <= ml_gettime())
	{
		printf("%zu %d died\n", (ml_gettime() - common->time_begin) \
			/ 1000, person->me);
		common->dying_message = 1;
		pthread_mutex_unlock(&common->mutex_print);
		pthread_mutex_unlock(person->mutex_right_fork);
		pthread_mutex_unlock(person->mutex_left_fork);
		return (1);
	}
	return (0);
}

int	person_eat_lr(t_philosopher *person, t_common *common)
{
	pthread_mutex_lock(person->mutex_left_fork);
	if (person_print(person, common, "has taken a fork"))
	{
		pthread_mutex_unlock(person->mutex_left_fork);
		return (1);
	}
	pthread_mutex_lock(person->mutex_right_fork);
	pthread_mutex_lock(&common->mutex_print);
	if (person_eat_lr_diecheck(person, common))
		return (1);
	person->last_eat = ml_gettime();
	printf("%zu %d has taken a fork\n%zu %d is eating\n", (person->last_eat - \
		common->time_begin) / 1000, person->me, (ml_gettime() - \
		common->time_begin) / 1000, person->me);
	pthread_mutex_unlock(&common->mutex_print);
	ml_sleep(common->time_to_eat);
	pthread_mutex_unlock(person->mutex_right_fork);
	pthread_mutex_unlock(person->mutex_left_fork);
	return (0);
}

int	person_eat_rl_diecheck(t_philosopher *person, t_common *common)
{
	if (cadaver_check_in_mutex(common))
	{
		pthread_mutex_unlock(&common->mutex_print);
		pthread_mutex_unlock(person->mutex_left_fork);
		pthread_mutex_unlock(person->mutex_right_fork);
		return (1);
	}
	if (person->last_eat + common->time_to_die <= ml_gettime())
	{
		printf("%zu %d died\n", (ml_gettime() - common->time_begin) \
			/ 1000, person->me);
		common->dying_message = 1;
		pthread_mutex_unlock(&common->mutex_print);
		pthread_mutex_unlock(person->mutex_left_fork);
		pthread_mutex_unlock(person->mutex_right_fork);
		return (1);
	}
	return (0);
}

int	person_eat_rl(t_philosopher *person, t_common *common)
{
	pthread_mutex_lock(person->mutex_right_fork);
	if (person_print(person, common, "has taken a fork"))
	{
		pthread_mutex_unlock(person->mutex_right_fork);
		return (1);
	}
	pthread_mutex_lock(person->mutex_left_fork);
	pthread_mutex_lock(&common->mutex_print);
	if (person_eat_rl_diecheck(person, common))
		return (1);
	person->last_eat = ml_gettime();
	printf("%zu %d has taken a fork\n%zu %d is eating\n", (person->last_eat - \
		common->time_begin) / 1000, person->me, (ml_gettime() - \
		common->time_begin) / 1000, person->me);
	pthread_mutex_unlock(&common->mutex_print);
	ml_sleep(common->time_to_eat);
	pthread_mutex_unlock(person->mutex_left_fork);
	pthread_mutex_unlock(person->mutex_right_fork);
	return (0);
}
