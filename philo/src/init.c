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

static int	check_atoi(t_info *info)
{
	if (info->number_ph < 1)
		return (printf("Philo error: wrong number of philo\n"), 1);
	if (info->die < 1)
		return (printf("Philo error: wrong time for die\n"), 1);
	if (info->eat < 1)
		return (printf("Philo error: wrong time for eat\n"), 1);
	if (info->sleep < 1)
		return (printf("Philo error: wrong time for sleep\n"), 1);
	if (info->eatmin < 0)
		return (printf("Philo error: wrong time of eat\n"), 1);
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

int	ft_init(t_info *info, char **argv, int argc)
{
	int	i;

	i = 0;
	info->number_ph = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->eatmin = ft_atoi(argv[5]);
	else
		info->eatmin = 0;
	if (check_atoi(info))
		return (1);
	info->philo = malloc(sizeof(t_philo *) * info->number_ph);
	if (!info->philo)
		return (printf("Philo error: malloc error\n"), 1);
	while (i < info->number_ph)
	{
		info->philo[i].id = i;
		info->philo[i].last_eat = 0;
		info->philo[i].eat_count = 0;
		info->philo[i].info = info;
		info->philo[i].lfork = info->philo[i - 1].fork;
	}
	return (0);
}
