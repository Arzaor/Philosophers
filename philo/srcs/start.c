/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:06:31 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/06 16:09:47 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start(t_pthread *pthread)
{
	int	i;

	i = -1;
	pthread->start = get_time();
	while (++i < pthread->np)
	{
		if (pthread_create(&pthread->philos[i].tid, NULL, routine, &pthread->philos[i]))
			ft_exit("Erreur lors de la creation des philosophers.");
		pthread->philos[i].last_meal = pthread->start;
	}
	death(pthread);
	i = -1;
	while (++i < pthread->np)
		pthread_join(pthread->philos[i].tid, NULL);
	destroy_mutex(pthread);
}