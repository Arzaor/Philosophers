/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:33:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/08/15 15:34:11 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	void	*routine(void	*p)
{
	t_pthread	*pthread;
	t_philos	*philos;

	pthread = init_pthread();
	philos = p; 
	printf("%d\n", pthread->np);
	return NULL;
}

void	destroy_mutex(t_pthread	*pthread)
{
	int	i;

	i = pthread->np;
	while (--i >= 0)
	{
		if (pthread_mutex_destroy(&pthread->chopsticks[i]))
			ft_exit("Erreur lors de la destruction des mutex pour les fourchettes.");
	}
	if (pthread_mutex_destroy(&pthread->food))
		ft_exit("Erreur lors de la destruction du mutex pour la nourriture.");
	if (pthread_mutex_destroy(&pthread->message))
		ft_exit("Erreur lors de la destruction du mutex pour les messages.");
}

void	start(t_pthread *pthread)
{
	int	i;

	i = 0;
	while (i < pthread->np)
	{
		if (pthread_create(&pthread->philos[i].tid, NULL, routine, &pthread->philos[i]))
			ft_exit("Erreur lors de la creation des philosophers.");
		i++;
	}
	i = 0;
	while (i < pthread->np)
	{
		pthread_join(pthread->philos[i].tid, NULL);
		i++;
	}
	destroy_mutex(pthread);
}