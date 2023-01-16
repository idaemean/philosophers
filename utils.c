/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:35:45 by iczarnie          #+#    #+#             */
/*   Updated: 2023/01/15 20:35:45 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	negativity;

	result = 0;
	negativity = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		negativity *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) == 1)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * negativity);
}

time_t	get_current_time_ms(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	sleeping(t_table *table, time_t sleeping_time)
{
	time_t	finish;

	finish = get_current_time_ms() + sleeping_time;
	while (!(simulation_stopped(table)) && get_current_time_ms() < finish)
		usleep(100);
}

void	print_status(t_table *table, t_philo *philo, const char *str)
{
	time_t	time_difference;

	time_difference = get_current_time_ms() - table->start_time;
	pthread_mutex_lock(&table->print_mutex);
	if (!simulation_stopped(table))
	{
		printf("%lld %d %s", time_difference, philo->id, str);
	}
	pthread_mutex_unlock(&table->print_mutex);
}
