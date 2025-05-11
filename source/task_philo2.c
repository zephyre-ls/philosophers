/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:36:13 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/11 19:21:13 by lduflot          ###   ########.fr       */
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
	if (philo->meals_left < philo->rules->nbr_meal)
		philo->meals_left++;
	if (philo->meals_left == philo->rules->nbr_meal)
		return (1);
	return (0);
}
