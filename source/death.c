/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:29:37 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/11 19:46:19 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->death_mutex);
	if (philo->rules->is_dead_end_simulation == 0)
		print_state_philo(philo, "is died 💀\n");
	pthread_mutex_unlock(&philo->rules->death_mutex);
}

int	death_or_not_death(t_philo *philo)
{
	int	result;

//	if (count_meal(philo))
	//	return(0); 
	//	Add condition quand un philosophe est rasasié ne pas verifier sa mort

	pthread_mutex_lock(&philo->rules->last_meal_mutex);
	result = real_time() - philo->last_meal;
	pthread_mutex_unlock(&philo->rules->last_meal_mutex);
	if (result >= philo->rules->time_to_die)
	{
		death_philo(philo);
		//pthread_mutex_lock(&philo->rules->end_simulation_mutex);
		if (philo->rules->is_dead_end_simulation == 0)
			philo->rules->is_dead_end_simulation = 1;
		//pthread_mutex_unlock(&philo->rules->end_simulation_mutex);
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
	print_state_philo(philo, "has finished all his meals. 🤤👉☕️ \n");
	pthread_mutex_unlock(&philo->rules->meal_empty_mutex);
}
