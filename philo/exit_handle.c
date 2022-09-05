/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:15:35 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/05 09:35:07 by mvieira-         ###   ########.fr       */
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
}

void	join_all_philos(t_data *data)
{
	int	i;
	
	i = 0; 
	while(i < (data->n_philo))
	{
		pthread_join(data->philos[i].tid , NULL);
		i++;
	}
	
}
void array_free(t_data *data)
{
	free(data->forks_m); 
	free(data->philos); 
}

void	exit_handle(t_data *data)
{
	destroy_all_mutex(data);
	join_all_philos(data);
	array_free(data);
}
