/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:36:07 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 13:05:20 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(int argc, char **argv)
{
	if (parsing_character(argc, argv))
		return (1);
	if (parsing_int(argc, argv))
		return (1);
	if (parsing_amount(argc, argv))
		return (1);
	parsing_save_to_struct(argc, argv);
	return (0);
}

int	parsing_character(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		while (argv[i][k])
		{
			if (!ft_isdigit(argv[i][k]))
				ft_exit("Uniquement des chiffres dans les arguments.");
			k++;
		}
		i++;
		k = 0;
	}
	return (0);
}

int	parsing_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			ft_exit("Les valeurs doivent être supérieures \
			à INT_MIN et inférieures à INT_MAX");
		i++;
	}
	return (0);
}

int	parsing_amount(int argc, char **argv)
{
	int	i;

	i = 2;
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		ft_exit("Veuillez vérifier le nombre de \
				philosophers. (MIN : 1, MAX : 200)");
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) < 60)
			ft_exit("Laissons leur du temps, c'est 60ms minimum.");
		i++;
	}
	return (0);
}

t_pthread	*parsing_save_to_struct(int argc, char **argv)
{
	t_pthread	*pthread;

	pthread = init_pthread();
	pthread->np = ft_atoi(argv[1]);
	pthread->ttd = ft_atoi(argv[2]);
	pthread->tte = ft_atoi(argv[3]);
	pthread->tts = ft_atoi(argv[4]);
	if (argc == 6)
		pthread->nte = ft_atoi(argv[5]);
	return (pthread);
}
