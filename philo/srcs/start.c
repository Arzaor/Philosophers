/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:06:31 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/22 13:39:39 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start(t_pthread *pthread)
{
	int	i;

	i = -1;
	pthread->start = get_time();
	while (++i < pthread->np)
	{
		if (pthread_create(&pthread->philos[i].tid, NULL, routine, \
							&pthread->philos[i]))
			return (ft_exit("Erreur lors de la creation des philosophers."));
		pthread->philos[i].last_meal = pthread->start;
	}
	death(pthread);
	i = -1;
	while (++i < pthread->np)
		pthread_join(pthread->philos[i].tid, NULL);
	if (destroy_mutex(pthread))
		return (1);
	return (0);
}
