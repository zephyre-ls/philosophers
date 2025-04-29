/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:41:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/29 12:13:06 by lduflot          ###   ########.fr       */
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

typedef struct s_rules
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_meal;
}			t_rules;

typedef struct s_philo
{
	pthread_t	thread_id;
	pthread_t	thread_dead;
	int			id;
	int			left_fork_id;
	int			right_fork_id;
	int			last_meal;
	int			meals_left;
	t_rules		*rules;
}			t_philo;

// Fonctions
// Parsing
int		ft_atoi(char *str);
int		only_number(char *argv);
int		parsing_args(int argc, char **argv);
// Time
int		real_time(void);
// Init thread, rules
int		init_argv(t_rules *rules, char **argv);
int		init_philo_fork(t_rules *rules, t_philo *philo);
void	init_last_meal(t_rules *rules, t_philo *philo);
void	init_nbr_meal(t_rules *rules, t_philo *philo);
int		create_thread(t_philo *philo, t_rules *rules);
void	*start_routine(void *arg);
void	print_state_philo(t_philo *philo, char *txt);
void	wait_threads_philo(t_philo *philo, t_rules *rules);
void	death_philo(t_philo *philo);
// Mutex
int		init_mutex(t_rules *rules);
void	free_mutex(t_philo *philo, t_rules *rules);

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
 */
