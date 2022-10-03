/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:08:11 by jbarette          #+#    #+#             */
/*   Updated: 2022/10/03 13:16:18 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_eat(t_philos *philo)
{
	pthread_mutex_lock(&philo->pthread->chopsticks[philo->pid]);
	pthread_mutex_lock(&philo->pthread->chopsticks[philo->pid + 1]);
	philo->last_meal = get_time();
	print_message(philo, "has taken a fork");
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	interval(philo->pthread, philo->pthread->tte);
	pthread_mutex_unlock(&philo->pthread->chopsticks[philo->pid]);
	pthread_mutex_unlock(&philo->pthread->chopsticks[philo->pid + 1]);
}

void	one_philo(t_philos *philo)
{
	pthread_mutex_lock(&philo->pthread->chopsticks[philo->right_f]);
	philo->last_meal = get_time();
	print_message(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->pthread->chopsticks[philo->right_f]);
	interval(philo->pthread, philo->pthread->ttd);
	print_message(philo, "is died");
	philo->pthread->dead = 1;
}

void	*routine(void *param)
{
	t_philos	*philo;

	philo = param;
	if (philo->pthread->np == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	if (philo->pid % 2 == 0)
		usleep(10000);
	while (philo->pthread->dead != 1)
	{
		routine_eat(philo);
		if (philo->pthread->all_ate)
			break ;
		print_message(philo, "is sleeping");
		interval(philo->pthread, philo->pthread->tts);
		print_message(philo, "is thinking");
		philo->ate++;
	}
	return (NULL);
}
