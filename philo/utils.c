/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:52:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/09 13:22:21 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_atoi(const char *nptr)
{
	int	signal;
	int	result;

	result = 0;
	signal = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
			nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
		{
			signal = -1;
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * signal);
}
