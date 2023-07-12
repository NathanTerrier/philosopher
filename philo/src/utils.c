/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/12 14:16:45 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_check_ded(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->last_eat >= philo->info->die)
	{
		ft_print(philo, "is dead\n");
		while (i < philo->info->number_ph)
			pthread_mutex_destroy(&philo->info->philo[i++].fork);
		free(philo->info->philo);
		exit(0);
	}
}

void	ft_usleep(t_philo *philo, int time)
{
	long long int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		ft_check_ded(philo);
		usleep(100);
	}
}

void	ft_print(t_philo *philo, char *str)
{
	long long int	time;

	time = ft_get_time();
	printf("%lld %d %s\n", time - philo->info->start, philo->id, str);
}

t_info	*ft_get_info(void)
{
	static t_info	*info;

	return (info);
}
