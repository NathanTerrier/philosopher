/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naterrie <naterrie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 00:16:41 by naterrie          #+#    #+#             */
/*   Updated: 2023/07/01 00:16:41 by naterrie         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 && argc != 6)
		return (printf("Philo error: wrong number of args\n"), 1);
	if (ft_check_args(argv))
		return (1);
	if (pthread_mutex_init(&info.print, NULL))
		return (printf("Philo error: mutex init error\n"), \
		free(info.philo), exit(1), 1);
	if (ft_init(&info, argv, argc))
		return (1);
	ft_start_routine(&info);
	ft_exit(info.philo);
	return (0);
}
