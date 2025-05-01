/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:29:37 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/01 15:48:00 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->death_mutex);
	print_state_philo(philo, "is died 💀 \n");
	pthread_mutex_unlock(&philo->rules->death_mutex);
}

int	death_or_not_death(t_philo *philo)
{
	int	result;

	result = real_time() - philo->last_meal;
	if (result >= philo->rules->time_to_die)
	{
		death_philo(philo);
		return (1);
	}
	return (0);
}

void	meal_empty(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->meal_empty_mutex);
	print_state_philo(philo, "has finished all his meals. 🤤👉☕️ \n");
	pthread_mutex_unlock(&philo->rules->meal_empty_mutex);
}
