/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/01 00:16:41 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	set_philo(t_philo *philo, t_info *info, int i)
{
	philo->id = i;
	philo->last_eat = 0;
	philo->eat_count = 0;
	philo->info = info;
	philo->dead = 0;
	if (i != 0)
		info->philo[i].lfork = &info->philo[i - 1].fork;
	if (pthread_mutex_init(&philo->fork, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	return (0);
}

static int	check_atoi(t_info *info)
{
	if (info->die < 1)
		return (printf("Philo error: wrong time for die\n"), 1);
	if (info->eat < 1)
		return (printf("Philo error: wrong time for eat\n"), 1);
	if (info->sleep < 1)
		return (printf("Philo error: wrong time for sleep\n"), 1);
	if (info->must_eat < 0)
		return (printf("Philo error: wrong time of eat\n"), 1);
	if (info->number_ph == 1)
		return (printf("%d %d is dead\n", info->die, 0), 1);
	if (info->number_ph < 2)
		return (printf("Philo error: wrong number of philo\n"), 1);
	return (0);
}

static int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	neg;

	i = 0;
	value = 0;
	neg = 1;
	if (str && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i])
	{
		if (value != ((value * 10) + (str[i] - '0')) / 10)
			return (-1);
		value = (value * 10) + (str[i++] - '0');
	}
	return (value *= neg);
}

static int	ft_init_philo(t_info *info)
{
	int	i;

	i = 0;
	info->philo = malloc(sizeof(t_philo) * info->number_ph);
	if (!info->philo)
		return (printf("Philo error: malloc error\n"), exit(1), 1);
	while (i < info->number_ph)
	{
		set_philo(&info->philo[i], info, i);
		i++;
	}
	if (pthread_mutex_init(&info->check, NULL))
		return (printf("Philo error: mutex init error\n"), \
		ft_exit(info->philo), 1);
	info->philo[0].lfork = &info->philo[i - 1].fork;
	info->dead = 0;
	return (0);
}

int	ft_init(t_info *info, char **argv, int argc)
{
	info->number_ph = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	else
		info->must_eat = 0;
	if (check_atoi(info))
		return (1);
	ft_init_philo(info);
	return (0);
}
