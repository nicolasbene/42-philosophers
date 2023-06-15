/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:19:52 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/15 17:20:08 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void philo_eat(t_philo *philo, t_philo_infos *infos)
// {
//     pthread_mutex_lock(philo->fork_left);
//     print(infos, FORK_MESSAGE, philo->id);
//     if (!philo->fork_right)
//     {
//         pthread_mutex_unlock(philo->fork_left);
//         ft_usleep(infos->time_to_die * 2, infos);
//         return;
//     }
//     pthread_mutex_lock(philo->fork_right);
//     print(infos, FORK_MESSAGE, philo->id);
//     print(infos, EAT_MESSAGE, philo->id);
//     philo->time_last_eat = get_time(infos->start_time);
//     ft_usleep(infos->time_to_eat, infos);
//     pthread_mutex_unlock(philo->fork_right);
//     pthread_mutex_unlock(philo->fork_left);
// }

static void philo_eat(t_philo *philo, t_philo_infos *infos)
{
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

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
    pthread_mutex_lock(first_fork);
    print(infos, FORK_MESSAGE, philo->id);
	pthread_mutex_lock(second_fork);
	print(infos, FORK_MESSAGE, philo->id);
    print(infos, EAT_MESSAGE, philo->id);
    philo->time_last_eat = get_time(infos->start_time);
    ft_usleep(infos->time_to_eat, infos);
    pthread_mutex_unlock(first_fork);
    print(infos, FORK_MESSAGE, philo->id);
	pthread_mutex_unlock(second_fork);
	print(infos, FORK_MESSAGE, philo->id);
}

static void	philo_sleep(t_philo *philo, t_philo_infos *infos)
{
	print(infos, SLEEP_MESSAGE, philo->id);
	ft_usleep(infos->time_to_sleep, infos);
}

static void	philo_think(t_philo *philo, t_philo_infos *infos)
{
	print(infos, THINK_MESSAGE, philo->id);
}

void	*philo_routine(void *arg)
{
	t_philo			*philo;
	t_philo_infos	*infos;

	philo = (t_philo *)arg;
	infos = philo->infos;
	philo->time_last_eat = get_time(infos->start_time);
	if (philo->id % 2 == 0)
		ft_usleep(infos->time_to_sleep / 10, infos);
	while (!someone_died(infos))
	{
		philo_eat(philo, infos);
		philo_sleep(philo, infos);
		philo_think(philo, infos);
	}
	usleep(10000);
	return (NULL);
}
