/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:29:37 by lduflot           #+#    #+#             */
/*   Updated: 2025/07/29 20:38:54 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->death_mutex);
	if (philo->rules->is_dead_end_simulation == 0)
		print_state_philo(philo, "is died 💀");
	pthread_mutex_unlock(&philo->rules->death_mutex);
}

int	death_or_not_death(t_philo *philo)
{
	int	result;
	int	status;

	status = 0;
	pthread_mutex_lock(&philo->rules->meal_mutex);
	status = (philo->meals_left == philo->rules->nbr_meal);
	pthread_mutex_unlock(&philo->rules->meal_mutex);
	if (status)
		return (0);
	pthread_mutex_lock(&philo->rules->last_meal_mutex);
	result = real_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->rules->last_meal_mutex);
	if (result > philo->rules->time_to_die + 2)
	{
		death_philo(philo);
		if (philo->rules->is_dead_end_simulation == 0)
			philo->rules->is_dead_end_simulation = 1;
		return (1);
	}
	return (0);
}

int	end_simulation(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&philo->rules->end_simulation_mutex);
	dead = philo->rules->is_dead_end_simulation;
	pthread_mutex_unlock(&philo->rules->end_simulation_mutex);
	return (dead);
}

void	meal_empty(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->meal_empty_mutex);
	print_state_philo(philo, "has finished all his meals. 🤤👉☕️");
	pthread_mutex_unlock(&philo->rules->meal_empty_mutex);
}
