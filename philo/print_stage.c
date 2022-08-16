/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:37:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/16 20:48:06 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void print_stage(t_data *data, int philo_id, char *log_message)
{
    printf("%lli %i %s\n", get_time() - data->first_time, philo_id, log_message);
}