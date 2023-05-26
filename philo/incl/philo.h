/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:26:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/05/26 17:34:23 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#endif

#include <stdio.h>

typedef struct s_philo_infos
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_times;
	int				over;
	int				eat_times;
	long			start_time;
	t_fork			*forks;
	pthread_mutex_t	over_mutex;
	pthread_mutex_t	eat_times_mutex;
}				t_philo_infos;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	long			time_last_eat;
	t_fork			*fork_left;
	t_fork			*fork_right;
	t_philo_infos	*infos;
}				t_philo;
