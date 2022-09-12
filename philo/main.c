/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:54:25 by mvieira-          #+#    #+#             */
/*   Updated: 2022/09/12 13:16:27 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		write(2, "Invalid Number of Arguments!\n", 28);
	}
	else
	{
		if (is_not_number(argv))
			write(2, "Argument is not a number!\n", 28);
		else
		{
			if (argc == 6)
			{
				data.n_eat = ft_atoi(argv[5]);
				data.five_parameter = 1;
			}
			else
				data.five_parameter = 0;
			initialization(&data, argv);
			create_thread(&data);
			exit_handle(&data);
		}
	}
	return (0);
}
