/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:09:11 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 12:51:24 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_pthread	*pthread;

	pthread = init_pthread();
	if (argc < 5 || argc > 6)
	{
		printf("Veuillez vérifier le nombre d'arguments.\n");
		return (1);
	}
	else
	{
		if (!(pthread))
			ft_exit("Erreur lors du malloc de la structure pthread.");
		if (parsing(argc, argv))
			return (1);
		if (init_philos())
			return (1);
		if (init_mutex(pthread))
			return (1);
		if (start(pthread))
			return (1);
	}
	return (0);
}
