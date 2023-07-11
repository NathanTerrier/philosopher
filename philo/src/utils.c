/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/11 23:59:30 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_check_ded(t_philo *philo)
{
	(void)philo;
	// ft_print(philo, "is dead\n");
	// exit(0);
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
	printf("%lld %d %s\n", ft_get_time() - time, philo->id, str);
}
