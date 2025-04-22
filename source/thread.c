/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/22 12:12:46 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_argv(t_rules *rules, char **argv)
{
	rules->nbr_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		rules->nbr_meal = ft_atoi(argv[5]);
		if (rules->nbr_meal <= 0)
		{
			printf("Number invalid\n");
			return(1);
		}
	}
	if (rules->nbr_philo < 2 || rules->time_to_die <= 0 || rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
	{
		printf("Number invalid\n");
		return(1);
	}
	return(0);
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
		philo[i].right_fork_id = i + 1;
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

void	*start_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	printf("Naissance du philosophe n°%d\n", philo->id);
	return (0);
}

/*char	print_state_philo(t_philo *philo)
{
	printf(real_time(), "%d has taken a fork 🍴\n", philo->thread_id);
	printf(real_time(), "%d is eating 🍝\n", philo->thread_id);
	printf(real_time(), "%d is sleeping 💤\n", philo->thread_id);
	printf(real_time(), "%d is thinking 🤔\n", philo->thread_id);
	printf(real_time(), "%d died 💀\n", philo->thread_id);
}*/

//pthread_t *thread 
// = pointeur vers une varialbe qui recoit l'id du thread crée 
// const pthread_attr_t *attr
// = pointeur vers une strcuture du thrrad//void *(start_routine)(void *)
// fonction que le thread va efffectuer , elle sera allo une fois le thread inité, on peut y mettre un return NULL
// void *arg
// = argument a passé a la fonction 
