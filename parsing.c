/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:34:53 by iczarnie          #+#    #+#             */
/*   Updated: 2023/01/15 20:34:53 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_over_max_int(const char *str)
{
	unsigned long long int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	if (result > 2147483647)
		return (-1);
	return (result);
}

int	only_digits(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	arguments_checker(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc - 1 < 4 || argc - 1 > 5)
		return (print_error(1));
	while (i < argc)
	{
		if (only_digits(argv[i]) != 0)
			return (print_error(2));
		if (check_over_max_int(argv[i]) == -1)
			return (print_error(3));
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (print_error(4));
	return (0);
}
