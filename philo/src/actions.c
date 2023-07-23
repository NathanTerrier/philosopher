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
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(&philo->fork);
	if (ft_check_ded(philo))
		return (ft_unlock(philo), 1);
	philo->last_eat = ft_actual_time(philo);
	if (ft_print(philo, "has taken a fork"))
		return (ft_unlock(philo));
	if (ft_print(philo, "is eating"))
		return (ft_unlock(philo));
	philo->eat_count++;
	if (ft_usleep(philo, philo->info->eat))
		return (ft_unlock(philo));
	ft_unlock(philo);
	if (ft_all_eat(philo))
		return (1);
	return (0);
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
	int	i;

	i = 0;
	while (i < philo->info->number_ph)
	{
		if (philo->info->dead == 1)
			return (1);
		if (ft_actual_time(philo) - philo->info->philo[i].last_eat >= philo->info->die)
		{
			philo->info->dead = 1;
			philo->info->philo[i].dead = 1;
			ft_print(&philo->info->philo[i], "is dead");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->info->must_eat == 0)
		return (0);
	while (i < philo->info->number_ph)
	{
		if (philo->info->philo[i].eat_count < philo->info->must_eat)
			return (0);
		i++;
	}
	return (1);
}
