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
	if (pthread_mutex_init(&info->check, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	if (pthread_mutex_init(&info->wait, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	if (pthread_mutex_init(&info->fork, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	return (0);
}

// static int	is_locked(t_philo *philo)
// {
// 	int	tmp;

// 	if (philo->id == 0)
// 		tmp = philo->info->number_ph - 1;
// 	else
// 		tmp = philo->id - 1;
// 	if (tmp == philo->id)
// 		return (1);
// 	if (philo->info->lock[philo->id] || philo->info->lock[tmp])
// 		return (1);
// 	ft_print(philo, "has taken a fork");
// 	ft_print(philo, "has taken a fork");
// 	return (0);
// }

int	lock_forks(t_philo *philo)
{
	// pthread_mutex_lock(&philo->info->wait);
	// while (is_locked(philo))
	// {
	// if (ft_check_ded(philo))
	// 	return (pthread_mutex_unlock(&philo->info->wait), 1);
	// }
	// philo->info->lock[philo->id] = 1;
	// if (philo->id == 0)
	// 	philo->info->lock[philo->info->number_ph - 1] = 1;
	// else
	// 	philo->info->lock[philo->id - 1] = 1;
	if (&philo->fork == philo->lfork)
	{
		ft_usleep(philo, philo->info->die);
		return (ft_check_ded(philo));
	}
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_unlock(&philo->info->wait);
	return (0);
}

int	ft_unlock(t_philo *philo)
{
	philo->info->lock[philo->id] = 0;
	if (philo->id == 0)
		philo->info->lock[philo->info->number_ph - 1] = 0;
	else
		philo->info->lock[philo->id - 1] = 0;
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->fork);
	return (0);
}
