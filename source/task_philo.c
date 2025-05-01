/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/01 20:11:57 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 * Prise des forks = ordre pair
 * Evite le dead_lock !
 *
 */

void	only_philo(t_philo *philo)
{
	philo->last_meal = real_time();
	if (philo->rules->nbr_philo == 1)
	{
		while (1)
		{
			if (death_or_not_death(philo) == 1)
				break ;
			print_state_philo(philo, "is thinking 💭");
			print_state_philo(philo, "is sleeping 💤");
			usleep(philo->rules->time_to_sleep * 1000);
		}
	}
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (death_or_not_death(philo) == 1)
			break ;
		if (philo->rules->nbr_philo == 1)
		{
			only_philo(philo);
			break ;
		}
		//printf("philo n*%d - dernier repas: %lld \n", philo->id, philo->last_meal);
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
		}
		else
		{
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
			pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
		}
		if (death_or_not_death(philo) == 1)
		{
			unlock_thread(philo);
			break ;
		}
		philo->last_meal = real_time();
		print_state_philo(philo, "is eating 🍝");
		//philo->last_meal = real_time();
		usleep(philo->rules->time_to_eat * 1000);
		//philo->last_meal = real_time();
		if (death_or_not_death(philo) == 1)
		{
			unlock_thread(philo);
			break ;
		}
	//	printf("philo n*%d - fini le repas: %lld \n", philo->id, philo->last_meal);
//		philo_take_fork(philo);
		if (death_or_not_death(philo) == 1)
		{
			death_philo(philo);
			unlock_thread(philo);
			break ;
		}
		count_meal(philo);
		if (count_meal(philo) == 1)
		{
			meal_empty(philo);
			unlock_thread(philo);
			break ;
		}
		unlock_thread(philo);
		philo_think_and_go_sleep(philo);
		if (death_or_not_death(philo) == 1)
			break ;
	}
	return (0);
}

void	print_state_philo(t_philo *philo, char *txt)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("⏲︎ %lld %d %s\n", real_time(), philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
