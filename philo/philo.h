/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:09:47 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/19 12:42:26 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>


struct s_data;

typedef struct s_philosopher
{
	int			nb;
	pthread_t	tid; 	
	struct s_data		*data;
	int			left_fork;
	int			right_fork;
} 	t_philosofer;

typedef struct	s_data
{
	int					n_philo;
	int					n_forks;
	int					t_eat;
	int					t_death;
	int					t_sleep;
	long long int		first_time;
	pthread_mutex_t		forks_m[100];
	t_philosofer		philos[100];
}	t_data;

long long	get_time();
void		initialization(t_data *data, char **argv);
int			ft_atoi(const char *nptr);
void		exit_handle(t_data *data);
void		create_thread(t_data *data);
void		print_stage(t_data *data, int philo_id, char *log_message);


#endif