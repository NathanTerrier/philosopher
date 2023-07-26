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

#include "philosopher.h"

int init_mutex(t_info *info)
{
	if (pthread_mutex_init(&info->check, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	if (pthread_mutex_init(&info->wait, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	if (pthread_mutex_init(&info->fork, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	if (pthread_mutex_init(&info->unfork, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	return (0);
}

static int	is_locked(t_philo *philo)
{
	int	idtemp;

	if (philo->id == 0)
		idtemp = philo->info->number_ph - 1;
	else
		idtemp = philo->id - 1;
	if (philo->info->lock[philo->id] == 1)
		return (1);
	if (philo->info->lock[idtemp] == 1)
		return (1);
	return (0);
}

int	ft_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork);
	while (is_locked(philo))
	{
		if (ft_check_ded(philo))
			return (pthread_mutex_unlock(&philo->info->fork), 1);
		usleep(100);
	}
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(&philo->fork);
	philo->info->lock[philo->id] = 1;
	if (philo->id == 0)
		philo->info->lock[philo->info->number_ph - 1] = 1;
	else
		philo->info->lock[philo->id - 1] = 1;
	pthread_mutex_unlock(&philo->info->fork);
	return (0);
}

int	ft_unlock(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->unfork);
	philo->info->lock[philo->id] = 0;
	if (philo->id == 0)
		philo->info->lock[philo->info->number_ph - 1] = 0;
	else
		philo->info->lock[philo->id - 1] = 0;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->info->unfork);
	return (0);
}
