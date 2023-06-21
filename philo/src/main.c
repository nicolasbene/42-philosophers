/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:19:32 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/21 18:02:33 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	free_all(t_philo_infos *infos, t_philo *philo)
{
	int	i;

	i = 0;
	if (infos->forks)
	{
		while (i < infos->nb_philo)
			pthread_mutex_destroy(&infos->forks[i++]);
		free(infos->forks);
	}
	if (philo)
		free(philo);
	return (0);
}

int	main(int ac, char **av)
{
	int				err;
	t_philo			*philos;
	t_philo_infos	infos;

	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	err = parse_args(av + 1, &infos);
	if (err != ALL_GOOD)
		return (error_msg(err));
	err = init_philosophers(&infos, &philos);
	if (err != ALL_GOOD)
	{
		free_all(&infos, NULL);
		return (error_msg(err));
	}
	err = init_thread(&infos, philos);
	if (err != ALL_GOOD)
	{
		free_all(&infos, philos);
		return (error_msg(err));
	}
	free_all(&infos, philos);
	return (0);
}
