/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/01 00:16:41 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info)
{
	if (pthread_mutex_init(&info->wait, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_return(info->philo));
	return (0);
}

int	lock_forks(t_philo *philo)
{
	if (&philo->fork == philo->lfork)
	{
		ft_usleep(philo, philo->info->die);
		return (ft_check_ded(philo));
	}
	// if (philo->info->number_ph % 2 != 0)
	// 	ft_usleep(philo, 5);
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->lfork);
	return (0);
}

int	ft_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}
