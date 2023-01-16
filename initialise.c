/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:07:00 by iczarnie          #+#    #+#             */
/*   Updated: 2023/01/16 15:07:00 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_table *table)
{
	int		i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->num_philo);
	table->fork = malloc(sizeof(pthread_mutex_t) * table->num_philo);
	if (!table->philo || !table->fork)
		return (print_error(5));
	while (i < table->num_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].fork[0] = i;
		table->philo[i].fork[1] = (i + 1) % table->num_philo;
		if (table->philo[i].id % 2)
		{
			table->philo[i].fork[0] = (i + 1) % table->num_philo;
			table->philo[i].fork[1] = i;
		}
		table->philo[i].meal_count = 0;
		table->philo[i].last_eat_time = table->start_time;
		pthread_mutex_init(&table->philo[i].eat_mutex, 0);
		table->philo[i].table = table;
		i++;
	}
	return (0);
}

int	init_global_mutexes(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->num_philo)
	{
		if (pthread_mutex_init(&table->fork[i], NULL))
			return (print_error(6));
	}
	if (pthread_mutex_init(&table->print_mutex, NULL))
		return (print_error(6));
	if (pthread_mutex_init(&table->finish_mutex, NULL))
		return (print_error(6));
	return (0);
}

t_table	*init_table(int argc, char **argv)
{
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->num_philo = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->start_time = get_current_time_ms();
	table->num_must_eat = -1;
	if (argc == 6)
		table->num_must_eat = ft_atoi(argv[5]);
	if (init_philo(table) != 0)
		return (NULL);
	table->finish = 0;
	if (init_global_mutexes(table) != 0)
		return (NULL);
	return (table);
}
