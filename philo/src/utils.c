/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:23:49 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/11 14:16:51 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_check_ded(t_philo *philo)
{
	(void)philo;
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

	time = ft_get_time() - philo->info->start;
	printf("%lld %d %s\n", time, philo->id, str);
}
