/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:19:32 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/15 15:23:47 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static void	free_all(t_philo_infos *infos, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < infos->nb_philo)
	{
		pthread_mutex_destroy(&infos->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&infos->over_mutex);
	pthread_mutex_destroy(&infos->eat_times_mutex);
	free(infos->forks);
	if (philo)
		free(philo);
}

void print_infos_philos(t_philo_infos *infos, t_philo *philos);

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

void print_infos_philos(t_philo_infos *infos, t_philo *philos)
{
	int	i;

	i = 0;
	printf("nb_philo: %d\n", infos->nb_philo);
	printf("time_to_die: %d\n", infos->time_to_die);
	printf("time_to_eat: %d\n", infos->time_to_eat);
	printf("time_to_sleep: %d\n", infos->time_to_sleep);
	printf("must_eat_times: %d\n", infos->must_eat_times);
	printf("over: %d\n", infos->over);
	printf("eat_times: %d\n", infos->eat_times);
	printf("start_time: %ld\n", infos->start_time);
	while (i < infos->nb_philo)
	{
		printf("philo[%d].id: %d\n", i, philos[i].id);
		printf("philo[%d].time_last_eat: %ld\n", i, philos[i].time_last_eat);
		printf("philo[%d].nb_eat: %d\n", i, philos[i].nb_eat);
		printf("philo[%d].fork_right: %p\n", i, philos[i].fork_right);
		printf("philo[%d].fork_left: %p\n", i, philos[i].fork_left);
		i++;
	}
}