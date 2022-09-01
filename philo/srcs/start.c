/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:33:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/08/31 23:44:44 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *param)
{
	t_philos	*philo;

	philo = param;
	printf("%d\n", philo->pid);
	/*	
	if (philo->pthread->np == 1)
		return (one_philo(philo));
	if (philo->pid % 2 == 0)
		usleep(1600);
	while (philo->pthread->dead != 1)
	{
		eat(philo);
		print_status(get_time(), philo, "is sleeping");
		usleep(philo->st_main->time_sleep * 1000);
		print_status(get_time(), philo, "is thinking");
		philo->n_meals++;
	}*/
	return (NULL);
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
	pthread->start = get_time();
	while (i < pthread->np)
	{
		if (pthread_create(&pthread->philos[i].tid, NULL, routine, &pthread->philos[i]))
			ft_exit("Erreur lors de la creation des philosophers.");
		pthread->philos[i].last_meal = pthread->start;
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