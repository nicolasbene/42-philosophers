/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:19:38 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/15 15:37:19 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	usage(const char *p_name)
{
	printf("Usage: %s nb_philo time_to_die time_to_eat", p_name);
	printf(" time_to_sleep [nb_times_must_eat]\n");
	return (1);
}

int	error_msg(int code)
{
	char	*s;

	if (code == PARSE_ERROR)
		s = "Error: something is wrong with the arguments";
	else if (code == PHILO_MALLOC_ERROR)
		s = "Error: could not allocate memory for the philosophers";
	else if (code == FORK_MALLOC_ERROR)
		s = "Error: could not allocate memory for the forks";
	else if (code == THREAD_INIT_ERROR)
		s = "Error: could not initalize the threads";
	else if (code == MUTEX_INIT_ERROR)
		s = "Error: could not initialize the mutex";
	else
		s = "An error occured during the program";
	printf("%s\n", s);
	return (code);
}
