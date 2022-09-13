/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:15:35 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/13 09:25:04 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	destroy_all_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_forks)
	{
		pthread_mutex_destroy(&(data->forks_m[i]));
		i++;
	}
	pthread_mutex_destroy(data->eat_m);
	pthread_mutex_destroy(data->five_p_m);
	pthread_mutex_destroy(data->print_m);
	pthread_mutex_destroy(data->data_loop_m);
	pthread_mutex_destroy(data->philo_last_meal_m);
}

void	join_all_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->n_philo))
	{
		pthread_join(data->philos[i].tid, NULL);
		i++;
	}
}

void	array_free(t_data *data)
{
	free(data->forks_m);
	free(data->philos);
	free(data->loop);
	free(data->all_ate);
	free(data->eat_m);
	free(data->five_p_m);
	free(data->print_m);
	free(data->forks);
}

void	exit_handle(t_data *data)
{
	join_all_philos(data);
	destroy_all_mutex(data);
	array_free(data);
}
