/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/12 02:21:54 by lduflot          ###   ########.fr       */
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
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			print_state_philo(philo, "has taken a fork ψ");
			print_state_philo(philo, "is thinking 💭");
			print_state_philo(philo, "is sleeping 💤");
			usleep(philo->rules->time_to_sleep * 1000);
			unlock_thread(philo);
		}
	}
}

void	*start_monitoring(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	while (!end_simulation(rules->philo))
	{
		i = 0;
		while (i < rules->nbr_philo)
		{
			if (death_or_not_death(&rules->philo[i])
				|| rules->philo_finish == rules->nbr_philo)
			{
				pthread_mutex_lock(&rules->end_simulation_mutex);
				rules->is_dead_end_simulation = 1;
				pthread_mutex_unlock(&rules->end_simulation_mutex);
				break ;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->rules->nbr_philo == 1)
		only_philo(philo);
	while (!end_simulation(philo))
	{
		if (day_start(philo))
		{
			unlock_thread(philo);
			break ;
		}
	}
	return (NULL);
}

int	day_start(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->rules->last_meal_mutex);
	philo->last_meal = real_time();
	pthread_mutex_unlock(&philo->rules->last_meal_mutex);
	print_state_philo(philo, "is eating 🍝");
	usleep(philo->rules->time_to_eat * 1000);
	if (count_meal(philo) == 1)
	{
		meal_empty(philo);
		return (1);
	}
	unlock_thread(philo);
	print_state_philo(philo, "is sleeping 💤");
	usleep(philo->rules->time_to_sleep * 1000);
	return (0);
}

void	take_forks(t_philo *philo)
{
	print_state_philo(philo, "is thinking  💭");
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
		print_state_philo(philo, "has taken a fork left ψ");
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
		print_state_philo(philo, "has taken a fork right ψ");
	}
	else
	{
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
		print_state_philo(philo, "has taken a fork right ψ");
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
		print_state_philo(philo, "has taken a fork left ψ");
	}
}
