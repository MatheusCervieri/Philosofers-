/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:09:47 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/16 13:16:45 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_data
{
	int				n_philo;
	int				n_forks;
	int				t_eat;
	int				t_death;
	int				t_sleep;
	pthread_mutex_t	forks_m[100];
}	t_data;

long long	get_time();
void		initialization(t_data *data, char **argv);
int			ft_atoi(const char *nptr);
void		exit_handle(t_data *data);



#endif