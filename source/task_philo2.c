/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:36:13 by lduflot           #+#    #+#             */
/*   Updated: 2025/07/30 08:16:26 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	unlock_thread(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
}

int	count_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->meal_mutex);
	if (philo->meals_left < philo->rules->nbr_meal)
		philo->meals_left++;
	if (philo->meals_left == philo->rules->nbr_meal)
	{
		philo->rules->philo_finish++;
		pthread_mutex_unlock(&philo->rules->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->rules->meal_mutex);
	return (0);
}

void	print_state_philo(t_philo *philo, char *txt)
{
	long	current;
	long	time;

	if (end_simulation(philo))
		return ;
	current = real_time();
	time = current - philo->rules->start_time;
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("\033[1;33m⏲︎\033[0m %5ld   %3d  %-20s\n", time, philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
