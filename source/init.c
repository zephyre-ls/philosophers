/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:15:19 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/29 14:52:27 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_argv(t_rules *rules, char **argv)
{
	rules->nbr_philo = ft_atoi(argv[1]);
	rules->time_to_die = ft_atoi(argv[2]);
	rules->time_to_eat = ft_atoi(argv[3]);
	rules->time_to_sleep = ft_atoi(argv[4]);
	if (rules->nbr_philo <= 0 || rules->time_to_die <= 0
		|| rules->time_to_eat <= 0 || rules->time_to_sleep <= 0)
	{
		printf("Erreur : Number invalid\n");
		return (1);
	}
	if (argv[5])
	{
		rules->nbr_meal = ft_atoi(argv[5]);
		if (rules->nbr_meal <= 0)
		{
			printf("Erreur : Number invalid\n");
			return (1);
		}
	}
	return (0);
}

void	init_nbr_meal(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		philo[i].meals_left = 0;
		i++;
	}
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
	while (i < rules->nbr_philo)
	{
		pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules->print_mutex, NULL);
	pthread_mutex_init(&rules->death_mutex, NULL);
	pthread_mutex_init(&rules->meal_empty_mutex, NULL);
	return (0);
}

int	init_philo_fork(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork_id = i;
		if (i + 1 < rules->nbr_philo)
			philo[i].right_fork_id = i + 1;
		else
			philo[i].right_fork_id = 0;
		philo[i].last_meal = real_time();
		philo[i].rules = rules;
		i++;
	}
	return (0);
}
