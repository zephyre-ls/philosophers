/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 11:41:39 by lduflot           #+#    #+#             */
/*   Updated: 2025/07/30 09:15:33 by lduflot          ###   ########.fr       */
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

typedef struct s_philo	t_philo;

typedef struct s_rules
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	meal_empty_mutex;
	pthread_mutex_t	end_simulation_mutex;
	pthread_mutex_t	last_meal_mutex;
	pthread_t		monitor_death_thread;
	long			start_time;
	int				is_dead_end_simulation;
	int				nbr_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_meal;
	int				philo_finish;
	t_philo			*philo;
}	t_rules;

typedef struct s_philo
{
	pthread_t	thread_id;
	pthread_t	thread_dead;
	long long	last_meal;
	int			id;
	int			left_fork_id;
	int			right_fork_id;
	int			meals_left;
	t_rules		*rules;
}			t_philo;

// Fonctions

// Time
long long	real_time(void);

// Parsing
int			ft_atoi(char *str);
int			only_number(char *argv);
int			parsing_args(int argc, char **argv);

// Init thread, rules
int			init_argv(t_rules *rules, char **argv);
int			init_philo_fork(t_rules *rules, t_philo *philo);
void		init_meal(t_rules *rules, t_philo *philo);
int			create_thread(t_philo *philo, t_rules *rules);
void		*start_routine(void *arg);
void		*start_monitoring(void *arg);
void		print_state_philo(t_philo *philo, char *txt);
void		wait_threads_philo(t_philo *philo, t_rules *rules);
void		only_philo(t_philo *philo);
void		take_forks(t_philo *philo);
int			count_meal(t_philo *philo);
void		unlock_thread(t_philo *philo);
int			day_start(t_philo *philo);
int			end_simulation(t_philo *philo);

// Mutex
int			init_mutex(t_rules *rules);
void		free_mutex(t_philo *philo, t_rules *rules);
void		death_philo(t_philo *philo);
int			death_or_not_death(t_philo *philo);
void		meal_empty(t_philo *philo);

#endif
