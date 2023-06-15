/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nibenoit <nibenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:26:15 by nibenoit          #+#    #+#             */
/*   Updated: 2023/06/15 10:47:21 by nibenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define ALL_GOOD 0
# define ERROR 1
# define PARSE_ERROR 2
# define PHILO_MALLOC_ERROR 3
# define FORK_MALLOC_ERROR 4
# define THREAD_INIT_ERROR 5
# define MUTEX_INIT_ERROR 6

# define DEBUG_MODE 0

# define DEAD 1
# define ALIVE 0
# define OVER 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# ifndef T_BOOL_H
#  define TRUE 1
#  define FALSE 0
# endif

# define INFO_MSG "%4ld \033[1;37m%d\033[0m %s\n"

# define FORK_MESSAGE	"has taken a fork"
# define EAT_MESSAGE	"\033[1;32mis eating\033[0m"
# define SLEEP_MESSAGE	"\033[1;34mis sleeping\033[0m"
# define THINK_MESSAGE	"\033[1;33mis thinking\033[0m"
# define DIE_MESSAGE	"\033[1;31mdied\033[0m"

typedef struct timeval	t_time;
typedef pthread_mutex_t	t_fork;

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

void	*philo_routine(void *args);
void	check_max_eat(t_philo_infos *infos);
void	ft_usleep(int ms, t_philo_infos *infos);
void	print(t_philo_infos *infos, char *str, int id);

int		ft_isdigit(int c);
int		error_msg(int code);
int		usage(const char *p_name);
int		someone_died(t_philo_infos *infos);
int		parse_args(char **args, t_philo_infos *infos);
int		init_thread(t_philo_infos *infos, t_philo *philos);
int		init_philosophers(t_philo_infos *infos, t_philo **philos_ptr);

long	get_time(long start);

#endif
