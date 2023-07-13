/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/14 01:08:28 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eat(t_philo *philo)
{
	ft_all_eat(philo);
	if (pthread_mutex_lock(philo->lfork))
		return ;
	if (pthread_mutex_lock(&philo->fork))
		return ;
	philo->last_eat = ft_get_time() - philo->info->start;
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	philo->eat_count++;
	ft_usleep(philo, philo->info->eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->fork);
	ft_all_eat(philo);
}

void	ft_sleep(t_philo *philo)
{
	ft_all_eat(philo);
	ft_print(philo, "is sleeping");
	ft_usleep(philo, philo->info->sleep);
	ft_check_ded(philo);
}

void	ft_think(t_philo *philo)
{
	ft_check_ded(philo);
	ft_all_eat(philo);
	ft_print(philo, "is thinking");
}

void	ft_check_ded(t_philo *philo)
{
	ft_all_eat(philo);
	if (philo->last_eat <= (ft_get_time() - philo->info->start) - philo->info->die)
	{
		ft_print(philo, "is dead");
		ft_exit(philo, 0);
	}
}

void	ft_all_eat(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->info->must_eat <= 0)
		return ;
	while (i < philo->info->number_ph)
	{
		if (philo->info->philo[i].eat_count < philo->info->must_eat)
			return ;
		i++;
	}
	free(philo->info->philo);
	exit(0);
}
