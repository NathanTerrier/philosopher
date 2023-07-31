/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:00:33 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/20 18:18:17 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	first_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		ft_think(philo);
		usleep(15000);
	}
	else if (philo->id - 1 == philo->info->number_ph \
		&& philo->info->number_ph > 1)
	{
		ft_think(philo);
		usleep(30000);
	}
}

static void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->info->wait);
	pthread_mutex_unlock(&philo->info->wait);
	philo->info->start = ft_get_time();
	first_routine(philo);
	while (1)
	{
		if (lock_forks(philo))
			return (NULL);
		if (ft_eat(philo))
			return (NULL);
		ft_unlock(philo);
		if (ft_sleep(philo))
			return (NULL);
		if (ft_think(philo))
			return (NULL);
	}
	return (NULL);
}

int	ft_start_routine(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&info->wait);
	while (i < info->number_ph)
	{
		if (pthread_create(&info->philo[i].thread, NULL, \
			&ft_philo_routine, &info->philo[i]) != 0)
		{
			printf("Philo error: pthread_create\n");
			ft_exit(&info->philo[0]);
		}
		i++;
	}
	i = 0;
	pthread_mutex_unlock(&info->wait);
	while (i < info->number_ph)
	{
		if (pthread_join(info->philo[i].thread, NULL))
			return (printf("Philo error: pthread_join\n"), \
				ft_exit(&info->philo[0]), 1);
		i++;
	}
	return (0);
}
