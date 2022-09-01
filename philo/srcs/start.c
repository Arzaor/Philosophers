/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:33:12 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/01 13:01:55 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pwait(t_pthread *m, long long time)
{
	long long	st;

	st = get_time();
	while (!m->dead)
	{
		if (get_time() - st >= time)
			break ;
		usleep(100);
	}
}

void	routine_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->pthread->chopsticks[philo->pid]);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->pthread->chopsticks[(philo->pid + 1) % philo->pthread->np]);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->pthread->food);
	print_message(philo, "is eating");
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->pthread->food);
	pwait(philo->pthread, philo->pthread->tte);
	pthread_mutex_unlock(&philo->pthread->chopsticks[philo->pid]);
	pthread_mutex_lock(&philo->pthread->chopsticks[(philo->pid + 1) % philo->pthread->np]);
}

void	*routine(void *param)
{
	t_philos	*philo;

	philo = param;
	if (philo->pthread->np == 1)
	{
		pthread_mutex_lock(&philo->pthread->chopsticks[philo->right_f]);
		philo->last_meal = get_time();
		print_message(philo, "has taken a fork");
		pthread_mutex_unlock(&philo->pthread->chopsticks[philo->right_f]);
		print_message(philo, "is died");
		philo->pthread->dead = 1;
		return (NULL);
	}
	if (philo->pid % 2)
		usleep(10000);
	while (philo->pthread->dead != 1)
	{
		routine_eat(philo);
		print_message(philo, "is sleeping");
		pwait(philo->pthread, philo->pthread->tts);
		print_message(philo, "is thinking");
		philo->ate++;
	}
	return (NULL);
}

void	destroy_mutex(t_pthread	*pthread)
{
	int	i;

	i = -1;
	while (++i < pthread->np)
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

	i = -1;
	pthread->start = get_time();
	while (++i < pthread->np)
	{
		if (pthread_create(&pthread->philos[i].tid, NULL, routine, &pthread->philos[i]))
			ft_exit("Erreur lors de la creation des philosophers.");
		pthread->philos[i].last_meal = pthread->start;
	}
	i = -1;
	while (++i < pthread->np)
		pthread_join(pthread->philos[i].tid, NULL);
	destroy_mutex(pthread);
}