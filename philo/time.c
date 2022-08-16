/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:28:03 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/16 20:45:43 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

/* A biblioteca do time mostra o tempo a partir de terminada data 1 de janeiro de 1970 (Epoch time.
	O t.tv_sec mostra a quantidade de segundos desde de aquela época. 
	O t.tvusec mostra a quantidade de microsegundos faltando desde de aquela época. 
*/

long long int	get_time()
{
	struct timeval		t;
	long long int		t_sec_mili;
	long long int		t_usec_mili;

	gettimeofday(&t, NULL);
	t_sec_mili = t.tv_sec * 1000;
	t_usec_mili = t.tv_usec / 1000;
	return (t_sec_mili + t_usec_mili);
}
