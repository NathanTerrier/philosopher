/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/19 08:02:07 by naterrie         ###   ########lyon.fr   */
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
	ft_all_eat(philo);
	if (philo->info->dead == 1 && philo->dead == 0)
		return ;
	pthread_mutex_lock(&philo->info->print);
	printf("%d %d %s\n", ft_actual_time(philo), philo->id, str);
	pthread_mutex_unlock(&philo->info->print);
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
	pthread_mutex_destroy(&philo->info->print);
	free(philo->info->philo);
	exit (code);
}
