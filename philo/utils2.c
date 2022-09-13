/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:21:48 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/13 16:29:33 by mvieira-         ###   ########.fr       */
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
