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
		usleep(100);
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

static void	free_all(t_info *info)
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
	pthread_mutex_destroy(&info->wait);
	pthread_mutex_destroy(&info->fork);
	pthread_mutex_destroy(&info->unfork);
	free(info->philo);
	free(info->lock);
}

void	ft_exit(t_philo *philo)
{
	free_all(philo->info);
	exit(1);
}

int	init_lock(t_info *info)
{
	int	i;

	i = 0;
	info->lock =  malloc(sizeof(int) * info->number_ph);
	if (!info->lock)
		return (printf("Philo error: malloc error\n"), \
		ft_exit(info->philo), 1);
	while (i < info->number_ph)
	{
		info->lock[i] = 0;
		i++;
	}
	return (0);
}
