/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:42:37 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/13 17:39:26 by mvieira-         ###   ########.fr       */
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
		data->philos[i].finished = 0;
		data->philos[i].last_meal = get_time();
		data->philos[i].left_fork_at_hand = 0;
		data->philos[i].right_fork_at_hand = 0;
		data->philos[i].forks_at_hand = 0;
		data->philos[i].nb = i;
		data->philos[i].data = data;
		data->philos[i].left_fork = i;
		if (data->n_philo == 1)
			data->philos[i].right_fork = -1;
		else
		{
			if (i == (data->n_philo - 1))
				data->philos[i].right_fork = 0;
			else
				data->philos[i].right_fork = i + 1;
		}
		i++;
	}
}

void	array_initiatilization(t_data *data)
{
	int	i;

	data->forks_m = malloc(sizeof(pthread_mutex_t) * data->n_forks);
	data->forks = malloc(sizeof(int) * data->n_forks);
	data->philos = malloc(sizeof(t_philosofer) * data->n_philo);
	data->eat_m = malloc(sizeof(pthread_mutex_t));
	data->five_p_m = malloc(sizeof(pthread_mutex_t));
	data->print_m = malloc(sizeof(pthread_mutex_t));
	data->data_loop_m = malloc(sizeof(pthread_mutex_t));
	i = 0;
	while (i < data->n_forks)
	{
		data->forks[i] = 0;
		i++;
	}
}

void	initialization(t_data *data, char **argv)
{
	int	*loop;

	if (data->five_parameter == 0)
		data->n_eat = 0;
	loop = malloc(sizeof(int));
	*loop = 1;
	data->loop = loop;
	data->all_ate = malloc(sizeof(int));
	*(data->all_ate) = 0;
	data->n_philo = ft_atoi(argv[1]);
	data->t_death = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_forks = data->n_philo;
	array_initiatilization(data);
	pthread_mutex_init(data->eat_m, NULL);
	pthread_mutex_init(data->five_p_m, NULL);
	pthread_mutex_init(data->print_m, NULL);
	pthread_mutex_init(data->data_loop_m, NULL);
	mutex_forks_initialization(data);
	philosofers_data_initialization(data);
}
