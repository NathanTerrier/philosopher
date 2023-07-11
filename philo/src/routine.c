/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:00:33 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/11 11:22:27 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	*ft_philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (0);
}

void	ft_start_routine(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_ph)
	{
		if (pthread_create(&info->philo[i].thread, NULL, \
			&ft_philo_routine, &info->philo[i]))
		{
			printf("Philo error: pthread_create\n");
			exit(1);
		}
		i++;
	}
}
