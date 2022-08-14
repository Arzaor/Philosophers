/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:09:15 by jbarette          #+#    #+#             */
/*   Updated: 2022/07/11 14:47:50 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_pthread
{
	int	np;
	int	ttd;
	int	tte;
	int	tts;
	int	nte;
}				t_pthread;

// PARSING
void		parsing(int argc, char **argv);
void		parsing_character(int argc, char **argv);
void		parsing_int(int argc, char **argv);
void		parsing_amount(int argc, char **argv);
t_pthread	*parsing_save_to_struct(int argc, char **argv);
void		ft_debug(t_pthread *pthread);

// UTILS
void		ft_exit(char *str);
t_pthread	*ft_init();
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);

#endif