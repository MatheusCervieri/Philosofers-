/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 23:09:47 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/16 12:54:59 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdio.h>
# include <sys/time.h>

typedef struct	s_data
{
	int	n_philo;
	int	t_eat;
	int	t_death;
	int	t_sleep;
}	t_data;

long long	get_time();
void		initialization(t_data *data, char **argv);
int			ft_atoi(const char *nptr);



#endif