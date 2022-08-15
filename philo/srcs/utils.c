/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarette <jbarette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:24:58 by jbarette          #+#    #+#             */
/*   Updated: 2022/08/15 13:41:35 by jbarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void		ft_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
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