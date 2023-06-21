/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:20:06 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/21 16:18:55 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_thread(t_philo_infos *infos, t_philo *philos)
{
	int				i;
	pthread_t		*threads;

	threads = malloc(infos->nb_philo * sizeof(*threads));
	if (!threads)
		return (THREAD_INIT_ERROR);
	infos->start_time = get_time(0);
	i = 0;
	while (i < infos->nb_philo)
	{
		if (pthread_create(&threads[i], NULL,
				&philo_routine, &philos[i]) != 0)
			return (THREAD_INIT_ERROR);
		i++;
	}
	i = 0;
	while (i < infos->nb_philo)
	{
		if (pthread_join(threads[i], NULL) != 0)
			return (THREAD_INIT_ERROR);
		i++;
	}
	free(threads);
	return (ALL_GOOD);
}
