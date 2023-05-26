/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:15:02 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/26 15:27:52 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
// #include <semaphore.h>

// pthread_t philosopher[5];
// pthread_mutex_t chopstick[5];

// void *func(int n)
// {
// 	printf("\nPhilosopher % d is thinking ", n);
// 	pthread_mutex_lock(&chopstick[n]); // when philosopher 5 is eating he takes fork 1 and fork 5
// 	pthread_mutex_lock(&chopstick[(n + 1) % 5]);
// 	printf("\nPhilosopher % d is eating ", n);
// 	sleep(3);
// 	pthread_mutex_unlock(&chopstick[n]);
// 	pthread_mutex_unlock(&chopstick[(n + 1) % 5]);
// 	printf("\nPhilosopher % d Finished eating ", n);
// }

#include "philo.h"

int	usage(const char *p_name)
{
	printf("Usage: %s nb_philo time_to_die time_to_eat", p_name);
	printf(" time_to_sleep [nb_times_must_eat]\n");
	return (1);
}

int	main(int ac, char *av[])
{
	if (ac < 5 || ac > 6)
		return (usage(av[0]));
	return (0);
}
