/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:19:59 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/21 17:05:13 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	get_philo(int id, t_philo_infos *infos)
{
	t_philo	philo;

	philo.id = id;
	philo.infos = infos;
	philo.time_last_eat = 0;
	philo.nb_eat = 0;
	philo.fork_left = &infos->forks[id - 1];
	philo.fork_right = NULL;
	if (infos->nb_philo > 1)
		philo.fork_right = &infos->forks[id % infos->nb_philo];
	return (philo);
}

void	check_max_eat(t_philo_infos *infos)
{
	pthread_mutex_lock(&infos->eat_times_mutex);
	if (infos->must_eat_times >= 0 && infos->eat_times == infos->nb_philo)
	{
		pthread_mutex_lock(&infos->over_mutex);
		infos->over = TRUE;
		pthread_mutex_unlock(&infos->over_mutex);
	}
	pthread_mutex_unlock(&infos->eat_times_mutex);
}

int	someone_died(t_philo_infos *infos)
{
	int	ret;

	pthread_mutex_lock(&infos->over_mutex);
	ret = infos->over;
	pthread_mutex_unlock(&infos->over_mutex);
	return (ret);
}

int	init_philosophers(t_philo_infos *infos, t_philo **philos_ptr)
{
	int		i;
	t_philo	*philos;

	philos = malloc(infos->nb_philo * sizeof(*philos));
	if (!philos)
		return (PHILO_MALLOC_ERROR);
	i = 0;
	while (i < infos->nb_philo)
	{
		philos[i] = get_philo(i + 1, infos);
		i++;
	}
	*philos_ptr = philos;
	return (ALL_GOOD);
}
