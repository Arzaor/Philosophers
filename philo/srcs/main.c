/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:09:11 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/09 14:04:22 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_pthread	*pthread;

	if (argc < 5 || argc > 6)
		ft_exit("Veuillez vérifier le nombre d'arguments.");
	pthread = init_pthread();
	if (!(pthread))
		ft_exit("Erreur lors du malloc de la structure pthread.");
	parsing(argc, argv);
	init_philos();
	init_mutex(pthread);
	start(pthread);
	return (0);
}
