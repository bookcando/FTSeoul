/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minsulee <minsulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:30:33 by minsulee          #+#    #+#             */
/*   Updated: 2023/03/17 16:51:21 by minsulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	person_sleep(t_philosopher *person, t_common *common)
{
	if (person_print(person, common, "is sleeping"))
		return (1);
	ml_sleep(common->time_to_sleep);
	return (0);
}

int	person_think(t_philosopher *person, t_common *common)
{
	if (person_print(person, common, "is thinking"))
		return (1);
	usleep(1000);
	return (0);
}

int	philosopher_thread_odd(t_philosopher *person, \
	t_common *common, ssize_t	must_eat)
{
	while (1)
	{
		if (cadaver_check(common))
			return (0);
		if (person_eat_lr(person, common))
			return (0);
		if (common->times_must_eat != -1)
		{
			must_eat--;
			if (must_eat == 0)
				return (1);
		}
		if (person_sleep(person, common))
			return (0);
		if (person_think(person, common))
			return (0);
	}
}

int	philosopher_thread_even(t_philosopher *person, \
	t_common *common, ssize_t must_eat)
{
	usleep(100);
	while (1)
	{
		if (cadaver_check(common))
			return (0);
		if (person_eat_rl(person, common))
			return (0);
		if (common->times_must_eat != -1)
		{
			must_eat--;
			if (must_eat == 0)
				return (1);
		}
		if (person_sleep(person, common))
			return (0);
		if (person_think(person, common))
			return (0);
	}
}

int	philosopher_run(t_philosopher **person, t_common **common, int *must_eat)
{
	if (!((*common)->times_must_eat != -1 && (*must_eat) == 0))
	{
		if (((*person)->me % 2))
		{
			if (philosopher_thread_odd((*person), (*common), \
				(*common)->times_must_eat) == 0)
				return (1);
		}
		else
		{
			if (philosopher_thread_even((*person), (*common), \
				(*common)->times_must_eat) == 0)
				return (1);
		}
	}
	return (0);
}
