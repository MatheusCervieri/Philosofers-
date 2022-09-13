/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:52:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/13 15:48:59 by mvieira-         ###   ########.fr       */
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

int	end_thread(t_data *data)
{
	pthread_mutex_lock(data->data_loop_m);
	if (*(data->loop) == 0)
	{
		pthread_mutex_unlock(data->data_loop_m);
		return (1);
	}	
	else
		pthread_mutex_unlock(data->data_loop_m);
	return (0);
}

int	end_thread_unlock(t_data *data, t_philosofer *philosofer)
{
	pthread_mutex_lock(data->data_loop_m);
	if (*(data->loop) == 0)
	{
		pthread_mutex_unlock(&(data->forks_m[philosofer->left_fork]));
		pthread_mutex_unlock(&(data->forks_m[philosofer->right_fork]));
		pthread_mutex_unlock(data->eat_m);
		pthread_mutex_unlock(data->data_loop_m);
		return (1);
	}
	else
		pthread_mutex_unlock(data->data_loop_m);
	return (0);
}

int	stop_checker(t_philosofer *philosofer, t_data *data)
{
	if (data->n_eat == philosofer->eats && data->five_parameter == 1)
	{
		philosofer->finished = 1;
		pthread_mutex_lock(data->five_p_m);
		*(data->all_ate) = *(data->all_ate) + 1;
		pthread_mutex_unlock(data->five_p_m);
		return (1);
	}
	return (0);
}

void	sleep_in_parts(int mili_sec)
{
	long long int	start_time;

	start_time = get_time();
	while (get_time() - start_time < mili_sec)
	{
		usleep(50);
	}
}
