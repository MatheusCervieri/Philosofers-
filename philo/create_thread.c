/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:58:04 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/19 17:51:42 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	eats(t_philosofer *philosofer)
{
	t_data	*data;

	data = philosofer->data;
	pthread_mutex_lock(&(data->forks_m[philosofer->left_fork]));
	print_stage_id(data, philosofer->nb, "has taken a fork", philosofer->left_fork);
	pthread_mutex_lock(&(data->forks_m[philosofer->right_fork]));
	print_stage_id(data, philosofer->nb, "has taken a fork", philosofer->right_fork);
	print_stage(data, philosofer->nb, "is eating");
	philosofer->last_meal = get_time();
	philosofer->eats = philosofer->eats + 1;
	///usleep(100000);
	usleep(data->t_eat * 1000);
	pthread_mutex_unlock(&(data->forks_m[philosofer->left_fork]));
	pthread_mutex_unlock(&(data->forks_m[philosofer->right_fork]));
}

void	*philo_function(void *t_philo)
{
	t_philosofer	*philosofer;
	t_data	*data;

	philosofer = (t_philosofer *) t_philo;
	data = philosofer->data;
	while (data->loop)
	{
		eats(philosofer);
		print_stage(data, philosofer->nb, "is sleeping");
		usleep(data->t_sleep * 1000);
		print_stage(data, philosofer->nb, "is thinking");
		if((get_time() - philosofer->last_meal) > data->t_death)
		{
			print_stage(data, philosofer->nb, "died");
			data->loop = 0;
		}
		if (data->n_eat == philosofer->eats)
			break ;
	}
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
