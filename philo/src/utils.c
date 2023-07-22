/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/22 15:06:16 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_usleep(t_philo *philo, int time)
{
	long long int	start;

	start = ft_get_time();
	while (ft_get_time() - start < time)
	{
		ft_check_ded(philo);
		usleep(100);
	}
	ft_check_ded(philo);
}

void	ft_print(t_philo *philo, char *str)
{
	long long int	time;

	time = ft_get_time();
	ft_all_eat(philo);
	if (philo->info->dead == 1 && philo->dead == 0)
		return ;
	printf("%lld %d %s\n", time - philo->info->start, philo->id, str);
	philo->dead = 0;
}

t_info	*ft_get_info(void)
{
	static t_info	*info;

	return (info);
}

void	ft_exit(t_philo *philo, int code)
{
	int	i;

	i = 0;
	while (i < philo->info->number_ph)
	{
		pthread_mutex_destroy(&philo->info->philo[i].fork);
		i++;
	}
	free(philo->info->philo);
	exit (code);
}
