/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:18:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/08/04 14:58:26 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdatomic.h>

typedef struct s_info
{
	int				number_ph;
	int				die;
	int				eat;
	int				sleep;
	int				must_eat;
	atomic_int		dead;
	int				isstart;
	long long int	start;
	struct s_philo	*philo;
	pthread_mutex_t	print;
	pthread_mutex_t	wait;
}	t_info;

typedef struct s_philo
{
	struct s_info	*info;
	int				id;
	int				eat_count;
	int				last_eat;
	pthread_t		thread;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	fork;
	int				dead;
}	t_philo;

// Actions //
int	ft_eat(t_philo *philo);
int	ft_sleep(t_philo *philo);
int	ft_think(t_philo *philo);
int	ft_all_eat(t_philo *philo);
int	ft_check_ded(t_philo *philo);

// Parsing //
int	ft_check_args(char **args);

// Initialization //
int	ft_init(t_info *info, char **argv, int argc);

// Routine //
int	ft_start_routine(t_info *info);

// Utils //
int	ft_usleep(t_philo *philo, int time);
int	ft_print(t_philo *philo, char *str);
int	ft_return(t_philo *philo);

// Mutex //
int	lock_forks(t_philo *philo);
int	ft_unlock(t_philo *philo);
int	init_mutex(t_info *info);

// Time //
int	ft_get_time(void);
int	ft_actual_time(t_philo *philo);

#endif
