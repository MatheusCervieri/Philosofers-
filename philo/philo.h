/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:09:47 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/05 12:01:31 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>


struct s_data;

typedef struct s_philosopher
{
	int			nb;
	int			left_fork_at_hand;
	int			right_fork_at_hand;
	int			forks_at_hand;
	pthread_t	tid; 	
	struct s_data		*data;
	int			left_fork;
	int			right_fork;
	long long int last_meal;
	int			eats;
} 	t_philosofer;

typedef struct	s_data
{
	int					n_philo;
	int					n_forks;
	int					t_eat;
	int					t_death;
	int					t_sleep;
	int					n_eat; 
	int					five_parameter; 
	long long int		first_time;
	int					*loop;
	int					*forks;
	pthread_mutex_t		*forks_m;
	t_philosofer		*philos;
}	t_data;

long long	get_time();
void		initialization(t_data *data, char **argv);
int			ft_atoi(const char *nptr);
void		exit_handle(t_data *data);
void		create_thread(t_data *data);
void		print_stage_id(t_data *data, int philo_id, char *log_message, int fork_id);
void print_stage(t_data *data, int philo_id, char *log_message);
int is_not_number(char **argv);


#endif