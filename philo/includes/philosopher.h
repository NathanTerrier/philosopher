/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:18:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/01 00:16:41 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				number_ph;
	int				die;
	int				eat;
	int				sleep;
	int				eatmin;
	long long int	start;
	struct s_philo	*philo;
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
}	t_philo;

// Parsing //
int		ft_check_args(char **args);

// Initialization //
int		ft_init(t_info *info, char **argv, int argc);

// Routine //
int		ft_start_routine(t_info *info);

// Actions //
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

// Utils //
void	ft_usleep(t_philo *philo, int time);
void	ft_print(t_philo *philo, char *str);
void	ft_check_ded(t_philo *philo);
t_info	*ft_get_info(void);

// Time //
int		ft_get_time(void);

#endif
