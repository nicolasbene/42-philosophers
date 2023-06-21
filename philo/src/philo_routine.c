/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:19:52 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/21 18:15:07 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_main(void *arg)
{
	long			death_time;
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *)arg;
	infos = philo->infos;
	ft_usleep(infos->time_to_die + 1, infos);
	pthread_mutex_lock(&infos->over_mutex);
	death_time = get_time(infos->start_time);
	if (!infos->over && death_time - philo->time_last_eat >= infos->time_to_die)
	{
		infos->over = TRUE;
		pthread_mutex_unlock(&infos->over_mutex);
		printf(INFO_MSG, death_time, philo->id, DIE_MESSAGE);
	}
	else
		pthread_mutex_unlock(&infos->over_mutex);
	return (NULL);
}

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	t_philo_infos	*infos;
	pthread_t		die_thread;

	philo = (t_philo *)arg;
	infos = philo->infos;
	philo->time_last_eat = get_time(infos->start_time);
	if (philo->id % 2 == 0)
		ft_usleep(infos->time_to_eat / 10, infos);
	while (!someone_died(infos))
	{
		pthread_create(&die_thread, NULL, &death_main, arg);
		pthread_detach(die_thread);
		if (infos->nb_philo > 1)
		{
			philo_eat(philo, infos);
			check_max_eat(infos);
			philo_sleep(philo, infos);
			philo_think(philo, infos);
		}
	}
	usleep(10000);
	return (NULL);
}
