/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/30 12:24:56 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
 * Prise des forks = ordre pair
 * Evite le dead_lock !
 *
 */

void	*start_routine(void *arg)
{
	t_philo	*philo;
	int		result;

	philo = (t_philo *)arg;
	while (1)
	{
		result = real_time() - philo->last_meal;
		if (result > philo->rules->time_to_die)
		{
			death_philo(philo);
			break ;
		}
		if (philo->rules->nbr_philo == 1)
		{
			philo->last_meal = real_time();
			while (1)
			{
				result = real_time() - philo->last_meal;
				if (result > philo->rules->time_to_die)
				{
					death_philo(philo);
					break ;
				}
				print_state_philo(philo, "is thinking 💭");
				print_state_philo(philo, "is sleeping 💤");
				usleep(philo->rules->time_to_sleep * 1000);
			}
			break ;
		}
		result = real_time() - philo->last_meal;
		if (result > philo->rules->time_to_die)
		{
			death_philo(philo);
			break ;
		}
		if (philo->id % 2 == 0)
		{
			result = real_time() - philo->last_meal;
			if (result > philo->rules->time_to_die)
			{
				death_philo(philo);
				break ;
			}
			pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
		}
		else
		{
			result = real_time() - philo->last_meal;
			if (result > philo->rules->time_to_die)
			{
				death_philo(philo);
				break ;
			}
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
		}
		print_state_philo(philo, "is eating 🍝");
		if (philo->meals_left < philo->rules->nbr_meal)
			philo->meals_left++;
		result = real_time() - philo->last_meal;
		if (result > philo->rules->time_to_die)
		{
			death_philo(philo);
			pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
			pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
			break ;
		}
		//printf("id : %d meals : %d\n", philo->id, philo->meals_left);
		if (philo->meals_left == philo->rules->nbr_meal)
		{
			meal_empty(philo);
			pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
			pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
			break ;
		}
		usleep(philo->rules->time_to_eat * 1000);
		philo->last_meal = real_time();
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
		result = real_time() - philo->last_meal;
		if (result > philo->rules->time_to_die)
		{
			death_philo(philo);
			break ;
		}
		print_state_philo(philo, "is thinking  💭");
		result = real_time() - philo->last_meal;
		if (result > philo->rules->time_to_die)
		{
			death_philo(philo);
			break ;
		}
		print_state_philo(philo, "is sleeping 💤");
		usleep(philo->rules->time_to_sleep * 1000);
		result = real_time() - philo->last_meal;
		if (result > philo->rules->time_to_die)
		{
			death_philo(philo);
			break ;
		}
	}
	return (0);
}

void	print_state_philo(t_philo *philo, char *txt)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("⏲︎ %lld %d %s\n", real_time(), philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
