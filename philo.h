/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iczarnie <iczarnie@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:23:13 by iczarnie          #+#    #+#             */
/*   Updated: 2023/01/11 11:23:13 by iczarnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				finish;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
}					t_table;		

typedef struct s_philo
{
	int				id;
	int				meal_count;
	int				fork[2];
	long long		last_eat_time;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	eat_mutex;
}					t_philo;

int		arguments_checker(int argc, char **argv);
int		ft_atoi(const char *str);
int		print_error(int err_nb);
time_t	get_current_time_ms(void);
t_table	*init_table(int argc, char **argv);
void	sleeping(t_table *table, time_t sleeping_time);
void	print_status(t_table *table, t_philo *philo, const char *str);

#endif