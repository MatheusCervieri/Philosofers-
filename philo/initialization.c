/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:42:37 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/19 18:48:52 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	mutex_forks_initialization(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_forks)
	{
		pthread_mutex_init(&(data->forks_m[i]), NULL);
		i++;
	}
}

void	philosofers_data_initialization(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].eats = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].nb = i;
		data->philos[i].data = data;
		data->philos[i].left_fork = i;
		if (i == (data->n_philo - 1))
			data->philos[i].right_fork = 0;
		else
			data->philos[i].right_fork = i + 1;
		i++;
	}
}

void array_initiatilization(t_data *data)
{
	data->forks_m = malloc(sizeof(pthread_mutex_t) * data->n_forks);
	data->philos = malloc(sizeof(t_philosofer) * data->n_philo);
}

void	initialization(t_data *data, char **argv)
{
	data->loop = 1;
	data->n_philo = ft_atoi(argv[1]);
	data->t_death = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_forks = data->n_philo;
	data->first_time = get_time();
	array_initiatilization(data);
	mutex_forks_initialization(data);
	philosofers_data_initialization(data);
}
