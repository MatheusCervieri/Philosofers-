/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:58:04 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/13 16:18:13 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	forks_unlock(t_philosofer *philosofer, t_data *data, int position)
{
	if (philosofer->left_fork > philosofer->right_fork && position == 0)
	{
		pthread_mutex_unlock(&(data->forks_m[philosofer->right_fork]));
	}
	else if (philosofer->left_fork > philosofer->right_fork && position == 1)
	{
		pthread_mutex_unlock(&(data->forks_m[philosofer->left_fork]));
	}
	else if (position == 0)
		pthread_mutex_unlock(&(data->forks_m[philosofer->left_fork]));
	else if (position == 1)
		pthread_mutex_unlock(&(data->forks_m[philosofer->right_fork]));
}

void	unlock_forks(t_data *data, t_philosofer *philosofer)
{
	forks_unlock(philosofer, data, 0);
	if (philosofer->right_fork != -1)
		forks_unlock(philosofer, data, 1);
}

void	forks_lock(t_philosofer *philosofer, t_data *data, int position)
{
	if (philosofer->left_fork > philosofer->right_fork && position == 0)
	{
		pthread_mutex_lock(&(data->forks_m[philosofer->right_fork]));
	}
	else if (philosofer->left_fork > philosofer->right_fork && position == 1)
	{
		pthread_mutex_lock(&(data->forks_m[philosofer->left_fork]));
	}
	else if (position == 0)
		pthread_mutex_lock(&(data->forks_m[philosofer->left_fork]));
	else if (position == 1)
		pthread_mutex_lock(&(data->forks_m[philosofer->right_fork]));
}

int	actions_util(t_philosofer *philosofer, t_data *data)
{
	pthread_mutex_lock(data->eat_m);
	if (end_thread_unlock(data, philosofer) == 1)
		return (1);
	data->forks[philosofer->left_fork] = 1;
	print_stage(data, philosofer->nb, "has taken a fork");
	data->forks[philosofer->right_fork] = 1;
	print_stage(data, philosofer->nb, "has taken a fork");
	philosofer->last_meal = get_time();
	print_stage(data, philosofer->nb, "is eating");
	pthread_mutex_unlock(data->eat_m);
	philosofer->eats = philosofer->eats + 1;
	sleep_in_parts(data->t_eat);
	data->forks[philosofer->left_fork] = 0;
	data->forks[philosofer->right_fork] = 0;
	unlock_forks(data, philosofer);
	if (stop_checker(philosofer, data) == 1)
		return (1);
	if (end_thread(data) == 1)
		return (1);
	return (0);
}



int	actions(t_philosofer *philosofer)
{
	t_data	*data;

	data = philosofer->data;
	if (end_thread(data) == 1)
		return (1);
	forks_lock(philosofer, data, 0);
	if (philosofer->right_fork != -1)
	{
		forks_lock(philosofer, data, 1);
		if ((data->forks[philosofer->left_fork] == 0)
			&& data->forks[philosofer->right_fork] == 0)
		{
			if (actions_util(philosofer, data) == 1)
				return (1);
			print_stage(data, philosofer->nb, "is sleeping");
			sleep_in_parts(data->t_sleep);
			if (end_thread(data) == 1)
				return (1);
			print_stage(data, philosofer->nb, "is thinking");
		}
	}
	else
		unlock_forks(data, philosofer);
	return (0);
}

void	*philo_function(void *t_philo)
{
	t_philosofer	*philosofer;
	t_data			*data;

	philosofer = (t_philosofer *) t_philo;
	data = philosofer->data;
	while (*(data->loop))
	{
		if (actions(philosofer) != 0)
			break ;
		if (end_thread(data) == 1)
			break ;
	}
	return (NULL);
}

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->first_time = get_time();
	while (i < data->n_philo)
	{	
		pthread_create(&(data->philos[i].tid), NULL,
			philo_function, &(data->philos[i]));
		i++;
	}
	if (data->five_parameter != 1 || data->n_philo == 1)
		death_checker(data);
	else
		death_checker_five_parameter(data);
}
