/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:42:37 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/16 20:44:27 by mvieira-         ###   ########.fr       */
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
		data->philos[i].nb = i;
		data->philos[i].data = data;
		i++;
	}
}

void	initialization(t_data *data, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->t_death = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->n_forks = data->n_philo;
	data->first_time = get_time();
	mutex_forks_initialization(data);
	philosofers_data_initialization(data);
}
