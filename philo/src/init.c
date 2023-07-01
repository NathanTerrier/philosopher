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

#include "../philosopher.h"

int	check_atoi(t_philo *philo)
{
	if (philo->number < 1)
		return (printf("Philo error: wrong number of philo\n"), 1);
	if (philo->die < 1)
		return (printf("Philo error: wrong time for die\n"), 1);
	if (philo->eat < 1)
		return (printf("Philo error: wrong time for eat\n"), 1);
	if (philo->sleep < 1)
		return (printf("Philo error: wrong time for sleep\n"), 1);
	if (philo->eatmin < 0)
		return (printf("Philo error: wrong time of eat\n"), 1);
	return (0);
}

int	ft_atoi(char *str)
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

int	init(t_philo *philo, char **argv, int argc)
{
	philo->number = ft_atoi(argv[1]);
	philo->die = ft_atoi(argv[2]);
	philo->eat = ft_atoi(argv[3]);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->eatmin = ft_atoi(argv[5]);
	else
		philo->eatmin = 0;
	if (check_atoi(philo))
		return (1);
	return (0);
}
