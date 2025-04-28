/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/28 09:15:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_argv(t_rules *rules, char **argv)
{
	rules->nbr_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (rules->nbr_philo < 2 || rules->time_to_die <= 0 || rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
	{
		printf("Number invalid\n");
		return(1);
	}
	if (argv[5])
	{
		rules->nbr_meal = ft_atoi(argv[5]);
		if (rules->nbr_meal <= 0)
		{
			printf("Number invalid\n");
			return(1);
		}
	}
	return (0);
}

void	init_last_meal(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
		while (i < rules->nbr_philo)
	{
		philo[i].last_meal = 0;
		i++;
	}
}

int	init_mutex(t_rules *rules)
{
	int	i;

	i = 0;
	while(i < rules->nbr_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules->print_mutex, NULL);
	pthread_mutex_init(&rules->death_mutex, NULL);
	return(0);
}

int	init_philo_fork(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while(i < rules->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork_id = i;
		printf("fork num left = %d\n", philo[i].left_fork_id);
		if (i + 1 < rules->nbr_philo)
		{
			philo[i].right_fork_id = i + 1;
			printf("fork num = %d\n", philo[i].right_fork_id);
		}
		else
		{
			philo[i].right_fork_id = 0;
			printf("2fork num = %d\n", philo[i].right_fork_id);
		}
		philo[i].last_meal = real_time();
		philo[i].rules = rules;
		i++;
	}
	return(0);
}

int	create_thread(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while(i < rules->nbr_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, start_routine, &philo[i]);
		i++;
	}
	return(0);
}

void	wait_threads_philo(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		pthread_join(philo[i].thread_id, NULL); //mentor qui attend que chaque thread se termine pour passer au suivant. 
		i++;
	}
}

//pthread_t *thread 
// = pointeur vers une varialbe qui recoit l'id du thread crée 
// const pthread_attr_t *attr
// = pointeur vers une strcuture du thrrad//void *(start_routine)(void *)
// fonction que le thread va efffectuer , elle sera allo une fois le thread inité, on peut y mettre un return NULL
// void *arg
// = argument a passé a la fonction 
