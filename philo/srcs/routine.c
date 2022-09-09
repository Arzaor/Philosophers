/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:08:11 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/09 11:15:22 by jbarette         ###   ########.fr       */
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
	usleep(philo->pthread->tte * 1000);
	pthread_mutex_unlock(&philo->pthread->chopsticks[philo->pid]);
	pthread_mutex_unlock(&philo->pthread->chopsticks[philo->pid + 1]);
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
		if (philo->pthread->all_ate)
			break ;
		print_message(philo, "is sleeping");
		usleep(philo->pthread->tts * 1000);
		print_message(philo, "is thinking");
		philo->ate++;
	}
	return (NULL);
}