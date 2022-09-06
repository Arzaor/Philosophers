/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:08:49 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/06 16:10:30 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_pthread	*pthread)
{
	int	i;

	i = -1;
	while (++i < pthread->np)
	{
		if (pthread_mutex_destroy(&pthread->chopsticks[i]))
			ft_exit("Erreur lors de la destruction des mutex pour les fourchettes.");
	}
	if (pthread_mutex_destroy(&pthread->message))
		ft_exit("Erreur lors de la destruction du mutex pour les messages.");
	if (pthread_mutex_destroy(&pthread->food))
		ft_exit("Erreur lors de la destruction du mutex pour la nourriture.");
}

void	death(t_pthread *m)
{
	int		i;

	i = -1;
	while (++i < m->np)
	{
		if (get_time() - m->philos[i].last_meal > m->ttd)
		{
			print_message(m->philos, "DIED");
			m->dead = 1;
			break ;
		}
		if (m->philos[i].ate == m->nte && m->nte > 0)
			m->all_ate++;
		if (m->all_ate == m->np)
		{
			m->dead = 1;
			break ;
		}
		if (i + 1 == m->np)
			i = -1;
		usleep(1600);
	}
}