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

#include "../philosopher.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		return (printf("Philo error: wrong number of args\n"), 1);
	if (check_args(argv))
		return (1);
	if (init(&philo, argv, argc))
		return (1);
	printf("nbr philo = %d\ntime die %d\ntime eat %d\ntime sleep %d\ntime of eat %d\n", philo.number, philo.die, philo.eat, philo.sleep, philo.eatmin);
	return (0);
}
