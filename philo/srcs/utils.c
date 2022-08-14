/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:24:58 by jbarette          #+#    #+#             */
/*   Updated: 2022/07/11 14:20:14 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}

t_pthread	*ft_init(void)
{
	t_pthread	*pthread;

	pthread = malloc(sizeof(t_pthread));
	pthread->np = 0;
	pthread->np = 0;
	pthread->ttd = 0;
	pthread->tte = 0;
	pthread->tts = 0;
	return (pthread);
}

int			ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	num;
	long long	n;

	num = 1;
	n = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\f') || (*str == '\r')
		|| (*str == '\n') || (*str == ' '))
		str++;
	if (*str == '-')
	{
		num *= -1;
		str++;
	}
	else
	{
		if (*str == '+')
			str++;
	}
	while ((*str >= '0' && *str <= '9'))
		n = (n * 10) + (*(str++) - '0');
	return (n * num);
}