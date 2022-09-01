/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 13:41:37 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/01 12:57:00 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_pthread	*init_pthread(void)
{
	static t_pthread	*pthread;

	if (!(pthread))
	{
		pthread = malloc(sizeof(t_pthread));
		memset(pthread, 0, sizeof(t_pthread));
	}
	if (!(pthread))
		ft_exit("Erreur lors du malloc de la structure pthread.");
	return (pthread);
}

void	init_mutex(t_pthread *pthread)
{
	int	i;

	i = pthread->np;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&pthread->chopsticks[i], NULL))
			ft_exit("Erreur lors l'initialisation des mutex pour les fourchettes.");
		pthread->philos[i].pid = i;
		pthread->philos[i].pthread = pthread;
	}
	if (pthread_mutex_init(&pthread->food, NULL))
		ft_exit("Erreur lors de l'initialisation du mutex pour la nourriture.");
	if (pthread_mutex_init(&pthread->message, NULL))
		ft_exit("Erreur lors de l'initialisation du mutex pour les messages.");
}

void	init_philos(void)
{
	t_pthread	*pthread;

	pthread = init_pthread();
	pthread->philos = (t_philos *)malloc(sizeof(t_philos) * pthread->np);
	memset(pthread->philos, 0, sizeof(t_philos));
	if (!(pthread->philos))
		ft_exit("Erreur lors du malloc des philosophers.");
	pthread->chopsticks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * pthread->np);
	if (!(pthread->chopsticks))
		ft_exit("Erreur lors du malloc des fourchettes.");
}