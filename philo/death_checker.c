/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:15:47 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/13 10:39:21 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	death_checker(t_data *data)
{
	int	i;

	while (*(data->loop))
	{
		i = 0;
		while (i < data->n_philo && *(data->loop) == 1)
		{
			pthread_mutex_lock(data->eat_m);
			if ((get_time() - data->philos[i].last_meal)
				> data->t_death && data->philos[i].finished != 1)
			{
				pthread_mutex_lock(data->data_loop_m);
				*(data->loop) = 0;
				pthread_mutex_unlock(data->data_loop_m);
				usleep(1000);
				print_stage(data, data->philos[i].nb, "died");
				pthread_mutex_unlock(data->eat_m);
			}
			else
				pthread_mutex_unlock(data->eat_m);
			i++;
		}
	}
}

void	death_checker_utils(t_data *data, int i)
{
	pthread_mutex_lock(data->data_loop_m);
	*(data->loop) = 0;
	pthread_mutex_unlock(data->data_loop_m);
	usleep(1000);
	print_stage(data, data->philos[i].nb, "died");
	*(data->all_ate) = data->n_philo;
	pthread_mutex_unlock(data->eat_m);
}

void	death_checker_five_parameter(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		if (*(data->all_ate) >= data->n_philo)
		{
			pthread_mutex_lock(data->data_loop_m);
			*(data->loop) = 0;
			pthread_mutex_unlock(data->data_loop_m);
			break ;
		}
		if (data->philos[i].finished == 0)
		{
			while (i < data->n_philo && *(data->loop) == 1)
			{
				pthread_mutex_lock(data->eat_m);
				if ((get_time() - data->philos[i].last_meal)
					> data->t_death && data->philos[i].finished != 1)
				{
					death_checker_utils(data, i);
				}
				else
					pthread_mutex_unlock(data->eat_m);
				i++;
			}
		}
	}
}
