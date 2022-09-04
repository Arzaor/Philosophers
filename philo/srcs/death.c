/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 01:02:05 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/03 01:14:45 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	deathwatch(t_pthread *m, t_philos *p)
{
	int		i;

	while (!m->all_ate)
	{
		i = -1;
		while (++i < m->np && !m->dead)
		{
			pthread_mutex_lock(&(m->food));
			if (get_time() - p[i].last_meal > m->ttd)
			{
				print_message(p, "died");
				m->dead = 1;
			}
			pthread_mutex_unlock(&(m->food));
		}
		if (m->dead)
			break ;
		i = 0;
		while (m->nte && i < m->np && p[i].ate >= m->nte)
			i++;
		if (i == m->np)
			m->all_ate = 1;
	}
}