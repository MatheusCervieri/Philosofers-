/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:37:12 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/19 14:08:29 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void print_stage(t_data *data, int philo_id, char *log_message, int fork_id)
{
    printf("%lli %i %s fork id:%d\n", get_time() - data->first_time, philo_id, log_message, fork_id);
}