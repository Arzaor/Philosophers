/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:09:15 by jbarette          #+#    #+#             */
/*   Updated: 2022/09/20 12:43:56 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_pthread	t_pthread;

typedef struct s_philos
{
	int			pid;
	long long	last_meal;
	int			ate;
	int			left_f;
	int			right_f;
	t_pthread	*pthread;
	pthread_t	tid;
}				t_philos;

typedef struct s_pthread
{
	int				np;
	int				ttd;
	int				tte;
	int				tts;
	int				nte;
	int				dead;
	int				all_ate;
	long long		start;
	t_philos		*philos;
	pthread_mutex_t	food;
	pthread_mutex_t	message;
	pthread_mutex_t	*chopsticks;
}				t_pthread;

// PARSING
int			parsing(int argc, char **argv);
int			parsing_character(int argc, char **argv);
int			parsing_int(int argc, char **argv);
int			parsing_amount(int argc, char **argv);
t_pthread	*parsing_save_to_struct(int argc, char **argv);

// INIT
t_pthread	*init_pthread(void);
int			init_mutex(t_pthread *pthread);
int			init_philos(void);

// START
int			start(t_pthread *pthread);

// ROUTINE
void		*routine(void *param);
void		one_philo(t_philos *philo);
void		routine_eat(t_philos *philo);

// DESTROY
void		destroy_mutex(t_pthread	*pthread);
void		death(t_pthread *m);

// UTILS
int			ft_exit(char *str);
int			ft_isdigit(int c);
long long	ft_atoi(const char *str);
void		print_message(t_philos *philos, char *str);

// TIME
long long	get_time(void);
void		interval(t_pthread *m, long long time);

#endif