/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:37:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/09 10:53:55 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void print_stage(t_data *data, int philo_id, char *log_message)
{
    pthread_mutex_lock(data->print_m);
    printf("%lli %i %s\n", get_time() - data->first_time, philo_id, log_message);
    pthread_mutex_unlock(data->print_m);
}
void print_stage_id(t_data *data, int philo_id, char *log_message, int fork_id)
{
    pthread_mutex_lock(data->print_m);
    printf("%lli %i %s fork id:%d\n", get_time() - data->first_time, philo_id, log_message, fork_id);
    pthread_mutex_unlock(data->print_m);
}