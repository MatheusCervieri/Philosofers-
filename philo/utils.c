/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:52:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/09 12:55:27 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	death_checker_utils(t_data *data, int i)
{
	pthread_mutex_lock(data->eat_m);
	*(data->loop) = 0;
	usleep(1000);
	print_stage(data, data->philos[i].nb, "died");
	pthread_mutex_unlock(data->eat_m);
}

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
