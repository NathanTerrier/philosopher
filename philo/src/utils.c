/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:23:49 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/11 11:27:54 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_check_ded(t_philo *philo)
{
	(void)philo;
	return (0);
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
