/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:28:03 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/09 12:40:07 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

long long int	get_time(void)
{
	struct timeval		t;
	long long int		t_sec_mili;
	long long int		t_usec_mili;

	gettimeofday(&t, NULL);
	t_sec_mili = t.tv_sec * 1000;
	t_usec_mili = t.tv_usec / 1000;
	return (t_sec_mili + t_usec_mili);
}
