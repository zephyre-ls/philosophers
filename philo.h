/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:41:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/22 12:13:15 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

//Stucture pour gérer mes philo
typedef struct s_rules
{
	int	nbr_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_meal;
	pthread_mutex_t *forks;
}			t_rules;

typedef struct s_philo
{
	int	id;
	pthread_t	thread_id;
	pthread_t	thread_dead;
	int	left_fork_id;
	int	right_fork_id;
	t_rules	*rules;
}			t_philo;

// Fonctions
// Parsing
int	ft_atoi(char *str);
int	only_number(char *argv);

// Time
int	real_time(void);

//Init thread, rules
int	init_argv(t_rules *rules, char **argv);
int	init_mutex(t_rules *rules);
int	init_philo_fork(t_rules *rules, t_philo *philo);
int	create_thread(t_philo *philo, t_rules *rules);
void	*start_routine(void *arg);

#endif

/*
 *	Memset
 *	Printf, write
 *	Malloc, free
 *	Usleep
 *	gettimeofday
 *	pthread_create
 *	pthread_detach
 *	pthread_join
 *	pthread_mutex_init
 *	pthread_mutex_lock
 *	pthread_mutex_unlock
 *	pthread_mutex_destroy
 *
 * Arguments :
 * number_of_philosophers
 * time_to_die
 * time_to_eat
 * time_to_sleep
 * [number_of_times_each_philosopher_must_eat]
 */
