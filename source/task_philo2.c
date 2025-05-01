/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:36:13 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/01 19:14:16 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*void	philo_take_fork(t_philo *philo)
{ 
	printf("philo n*%d - dernier repas: %lld \n", philo->id, philo->last_meal);
	if (philo->id % 2 == 0)
	{ 
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
		print_state_philo(philo, "has taken a fork ψ");
	}
	else
	{
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
		print_state_philo(philo, "has taken a fork ψ");
	}
	if (death_or_not_death(philo) == 1);
		break ;
	print_state_philo(philo, "is eating 🍝");
	usleep(philo->rules->time_to_eat * 1000);
	philo->last_meal = real_time();
	printf("philo n*%d - fini le repas: %lld \n", philo->id, philo->last_meal);
}*/

void	philo_think_and_go_sleep(t_philo *philo)
{
	print_state_philo(philo, "is thinking  💭");
	print_state_philo(philo, "is sleeping 💤");
	usleep(philo->rules->time_to_sleep * 1000);
}

void	unlock_thread(t_philo *philo)
{
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
	pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
}

int	count_meal(t_philo *philo)
{
	if (philo->meals_left < philo->rules->nbr_meal)
		philo->meals_left++;
	if (philo->meals_left == philo->rules->nbr_meal)
		return (1);
	return (0);
}
