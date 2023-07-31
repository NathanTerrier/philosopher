/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/20 14:15:24 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_usleep(t_philo *philo, int time)
{
	long long int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		if (ft_check_ded(philo))
			return (1);
		usleep(500);
	}
	if (ft_check_ded(philo))
		return (1);
	return (0);
}

int	ft_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->info->print);
	if (philo->info->dead == 1 && philo->dead == 0)
		return (pthread_mutex_unlock(&philo->info->print), 0);
	printf("%d %d %s\n", ft_actual_time(philo), philo->id, str);
	pthread_mutex_unlock(&philo->info->print);
	philo->dead = 0;
	return (0);
}

int	ft_unlock(t_philo *philo)
{
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(&philo->fork);
	return (1);
}

void	free_all(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_ph)
	{
		pthread_mutex_destroy(&info->philo[i].fork);
		i++;
	}
	pthread_mutex_destroy(&info->check);
	pthread_mutex_destroy(&info->print);
	free(info->philo);
}

void	ft_exit(t_philo *philo)
{
	free_all(philo->info);
	exit(1);
}
