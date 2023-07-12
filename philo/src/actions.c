/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:46:35 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/12 14:13:39 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_philo *philo)
{
	if (pthread_mutex_lock(philo->lfork))
		return ;
	if (pthread_mutex_lock(&philo->fork))
		return ;
	philo->last_eat = ft_get_time() - philo->info->start;
	ft_print(philo, "is eating");
	ft_usleep(philo, philo->info->eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->fork);
}

void	ft_sleep(t_philo *philo)
{
	ft_print(philo, "is sleeping");
	ft_usleep(philo, philo->info->sleep);
	ft_check_ded(philo);
}

void	ft_think(t_philo *philo)
{
	ft_check_ded(philo);
	ft_print(philo, "is thinking");
}
