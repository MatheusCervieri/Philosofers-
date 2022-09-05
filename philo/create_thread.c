/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:58:04 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/05 12:24:27 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int take_forks(t_philosofer *philosofer)
{
	t_data *data;
	data = philosofer->data;
	if (*(data->loop) == 0)
			return (1);
	pthread_mutex_lock(&(data->forks_m[philosofer->left_fork]));
	if (data->forks[philosofer->left_fork] == 0)
	{
		data->forks[philosofer->left_fork] = 1;
		philosofer->left_fork_at_hand = philosofer->left_fork_at_hand + 1;
		print_stage_id(data, philosofer->nb, "has taken a fork", philosofer->left_fork);
	}
	pthread_mutex_unlock(&(data->forks_m[philosofer->left_fork]));
	pthread_mutex_lock(&(data->forks_m[philosofer->right_fork]));
	if (data->forks[philosofer->right_fork] == 0)
	{
		data->forks[philosofer->right_fork] = 1;
		philosofer->right_fork_at_hand = philosofer->right_fork_at_hand + 1;
		print_stage_id(data, philosofer->nb, "has taken a fork", philosofer->right_fork);
	}
	pthread_mutex_unlock(&(data->forks_m[philosofer->right_fork]));
	return (0);
}

int	eats(t_philosofer *philosofer)
{
	t_data	*data;

	data = philosofer->data;
	if (*(data->loop) == 0)
			return (1);
	if (philosofer->left_fork_at_hand == 1 && philosofer->right_fork_at_hand == 1)
	{	
	philosofer->last_meal = get_time();
	print_stage(data, philosofer->nb, "is eating");
	philosofer->eats = philosofer->eats + 1;
	///usleep(100000);
	usleep(data->t_eat * 1000);
	if (philosofer->left_fork_at_hand == 1)
		data->forks[philosofer->left_fork] = 0;
	if (philosofer->right_fork_at_hand == 1)
		data->forks[philosofer->right_fork] = 0;
	if (*(data->loop) == 0)
			return (1);
	print_stage(data, philosofer->nb, "is sleeping");
	usleep(data->t_sleep * 1000);
	if (*(data->loop) == 0)
			return (1);
	print_stage(data, philosofer->nb, "is thinking");
	}
	return (0);

}

void	*philo_function(void *t_philo)
{
	t_philosofer	*philosofer;
	t_data	*data;

	philosofer = (t_philosofer *) t_philo;
	data = philosofer->data;
	while (*(data->loop))
	{
		
		if (take_forks(philosofer) != 0)
			break ;
		if ((get_time() - philosofer->last_meal) > data->t_death)
		{
			// corrigir todos morendo ao mesmo tempo. 
			print_stage(data, philosofer->nb, "died");
			*(data->loop) = 0;
		}
		if(*(data->loop) == 0)
			break ;
		if (eats(philosofer) != 0)
			break ;
		if (data->n_eat == philosofer->eats && data->five_parameter == 1)
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
