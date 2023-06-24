/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:15:30 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/24 16:23:56 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_take_forks(t_philo *philo, t_philo_infos *infos,
	pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	pthread_mutex_lock(first_fork);
	print(infos, FORK_MESSAGE, philo->id);
	pthread_mutex_lock(second_fork);
	print(infos, FORK_MESSAGE, philo->id);
	print(infos, EAT_MESSAGE, philo->id);
}

static void	philo_release_forks(t_philo *philo, t_philo_infos *infos,
	pthread_mutex_t *first_fork, pthread_mutex_t *second_fork)
{
	pthread_mutex_unlock(first_fork);
	print(infos, FORK_MESSAGE, philo->id);
	pthread_mutex_unlock(second_fork);
	print(infos, FORK_MESSAGE, philo->id);
}

void	philo_eat(t_philo *philo, t_philo_infos *infos)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id % 2 == 0)
	{
		first_fork = philo->fork_right;
		second_fork = philo->fork_left;
	}
	else
	{
		first_fork = philo->fork_left;
		second_fork = philo->fork_right;
	}
	philo_take_forks(philo, infos, first_fork, second_fork);
	if (!someone_died(infos))
	{
		philo->nb_eat++;
		pthread_mutex_lock(&infos->eat_times_mutex);
		if (philo->nb_eat == infos->must_eat_times)
			infos->eat_times++;
		pthread_mutex_unlock(&infos->eat_times_mutex);
	}
	philo->time_last_eat = get_time(infos->start_time);
	ft_usleep(infos->time_to_eat, infos);
	philo_release_forks(philo, infos, first_fork, second_fork);
}

void	philo_sleep(t_philo *philo, t_philo_infos *infos)
{
	print(infos, SLEEP_MESSAGE, philo->id);
	ft_usleep(infos->time_to_sleep, infos);
}

void	philo_think(t_philo *philo, t_philo_infos *infos)
{
	print(infos, THINK_MESSAGE, philo->id);
}
