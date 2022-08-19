/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:58:04 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/19 12:25:14 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	eats(t_philosofer *philosofer)
{
	t_data	*data;

	data = philosofer->data;
	pthread_mutex_lock(&(data->forks_m[philosofer->left_fork]));
	print_stage(data, philosofer->nb, "has taken a fork");
	printf("Fork number %i \n", philosofer->left_fork);
	pthread_mutex_lock(&(data->forks_m[philosofer->right_fork]));
	print_stage(data, philosofer->nb, "has taken a fork");
	printf("Fork number %i \n", philosofer->right_fork);
	pthread_mutex_unlock(&(data->forks_m[philosofer->left_fork]));
	pthread_mutex_unlock(&(data->forks_m[philosofer->right_fork]));
}

void	*philo_function(void *t_philo)
{
	t_philosofer	*philosofer;

	philosofer = (t_philosofer *) t_philo;
	print_stage(philosofer->data, philosofer->nb, "I was created");
	eats(philosofer);
	return (NULL);
}

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{	
		pthread_create(&(data->philos[i].tid), NULL, philo_function, &(data->philos[i]));
		i++;
	}
}
