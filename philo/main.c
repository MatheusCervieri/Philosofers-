/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvieira- <mvieira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:54:25 by mvieira-          #+#    #+#             */
/*   Updated: 2022/08/19 21:05:49 by mvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	0- Tratar os erros - malloc[x], número de argumentos...
	1- Lidar com a exceção de apenas um filósofo.
	2- Lidar com o problema que os filosofos estão pegando o mesmo garfo --> posso criar um array que armazena se o garfo já foi pego ou não.
	3- Check how the death of the philosofer is verified. (Ver a régua).
	4- Fazer os testes da régua.
	5- Fazer os testes. 
*/

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		write(2, "Invalid Number of Arguments!\n", 28);
	}
	else
	{
		if(is_not_number(argv))
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
