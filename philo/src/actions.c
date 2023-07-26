/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/20 18:33:11 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_eat(t_philo *philo)
{
	if (ft_lock(philo))
		return (1);
	philo->last_eat = ft_actual_time(philo);
	if (ft_print(philo, "has taken a fork"))
		return (ft_unlock(philo));
	if (ft_print(philo, "has taken a fork"))
		return (ft_unlock(philo));
	if (ft_print(philo, "is eating"))
		return (ft_unlock(philo));
	philo->eat_count++;
	if (ft_usleep(philo, philo->info->eat))
		return (ft_unlock(philo));
	if (ft_all_eat(philo))
		return (ft_unlock(philo), 1);
	return (ft_unlock(philo), 0);
}

int	ft_sleep(t_philo *philo)
{
	if (ft_print(philo, "is sleeping"))
		return (1);
	return (ft_usleep(philo, philo->info->sleep));
}

int	ft_think(t_philo *philo)
{
	return (ft_print(philo, "is thinking"));
}

int	ft_check_ded(t_philo *philo)
{
	atomic_int	ded;

	ded = 0;
	pthread_mutex_lock(&philo->info->check);
	while (ded < philo->info->number_ph)
	{
		if (philo->info->dead == 1)
			return (pthread_mutex_unlock(&philo->info->check), 1);
		if (ft_actual_time(philo) - \
		philo->info->philo[ded].last_eat >= philo->info->die)
		{
			philo->info->dead = 1;
			philo->info->philo[ded].dead = 1;
			ft_print(&philo->info->philo[ded], "is dead");
			return (pthread_mutex_unlock(&philo->info->check), 1);
		}
		ded++;
	}
	pthread_mutex_unlock(&philo->info->check);
	return (0);
}

int	ft_all_eat(t_philo *philo)
{
	atomic_int	eat;

	eat = 0;
	if (philo->info->must_eat == 0)
		return (0);
	while (eat < philo->info->number_ph)
	{
		if (philo->info->philo[eat].eat_count \
				< philo->info->must_eat)
			return (0);
		eat++;
	}
	return (1);
}
