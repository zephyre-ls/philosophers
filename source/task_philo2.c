/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:36:13 by lduflot           #+#    #+#             */
/*   Updated: 2025/08/02 10:39:37 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Liberation des forks
*/
void	unlock_thread(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
}

/*
Incremente nbr meal
*/
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

	pthread_mutex_lock(&philo->rules->print_mutex);
	if (end_simulation(philo))
	{
		pthread_mutex_unlock(&philo->rules->print_mutex);
		return ;
	}
	current = real_time();
	time = current - philo->rules->start_time;
	printf("%ld   %d  %s\n", time, philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
