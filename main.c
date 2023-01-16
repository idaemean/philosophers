/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:26:11 by iczarnie          #+#    #+#             */
/*   Updated: 2023/01/11 11:26:11 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int err_nb)
{
	if (err_nb == 1)
		printf("Invalid number of arguments \n");
	if (err_nb == 2)
		printf("Non numeric argument \n");
	if (err_nb == 3)
		printf("Argument over max int\n");
	if (err_nb == 4)
		printf("Zero philosophers is impossible\n");
	if (err_nb == 5)
		printf("Malloc error\n");
	if (err_nb == 6)
		printf("Mutex error\n");
	return (err_nb);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (arguments_checker(argc, argv) != 0)
		return (1);
	table = init_table(argc, argv);
	return (0);
}
