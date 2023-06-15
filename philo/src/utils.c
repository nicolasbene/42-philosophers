/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:20:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/15 13:46:53 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (FALSE);
	return (TRUE);
}

void print(t_philo_infos *infos, char *str, int id)
{
	pthread_mutex_lock(&infos->over_mutex);
	if (!infos->over)
		printf("%ld %d %s\n", get_time(infos->start_time), id, str);
	pthread_mutex_unlock(&infos->over_mutex);
}

void	ft_usleep(int ms, t_philo_infos *infos)
{
	long	start;
	long	end;

	start = get_time(infos->start_time);
	end = start + ms;
	while (!someone_died(infos) && get_time(infos->start_time) < end)
		usleep(100);
}
