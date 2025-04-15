/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:41:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/15 16:14:14 by lduflot          ###   ########.fr       */
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
typedef struct s_philo
{
	int			id;
	pthread_t	thread_id;
	pthread_t	thread_dead;
	mutex	nbr_fork;
	mutex	left_fork;
	mutex	right_fork;
}			t_philo;

typedef struct s_rules
{
	t_philo	
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_meal;
}			t_rules;

// Fonctions
// Parsing
int	error_nbr_philo(char *argv);
int	ft_atoi(char *arg);
int	only_number(char *argv);

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
