/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/29 12:15:42 by lduflot          ###   ########.fr       */
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
		if (philo->id % 2 == 0)
		{
			pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
			print_state_philo(philo, "has taken a left.fork 🍴");
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			print_state_philo(philo, "has taken a right.fork 🍴");
		}
		else
		{
			pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
			print_state_philo(philo, "has taken a right.fork 🍴");
			pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
			print_state_philo(philo, "has taken a left.fork 🍴");
		}
		print_state_philo(philo, "is eating 🍝");
		philo->meals_left++;
		printf("id : %d meals : %d\n", philo->id, philo->meals_left);
		//faire une fonction qui if meals_left == nbr_meal break !
		usleep(philo->rules->time_to_eat * 1000);
		philo->last_meal = real_time();
		//printf("%d last_meal %d : \n", philo->id, philo->last_meal);
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
		print_state_philo(philo, "a poser les 2 fork\n");
		print_state_philo(philo, "is sleeping 💤");
		usleep(philo->rules->time_to_sleep * 1000);
		print_state_philo(philo, "is thinking 🤔");
		result = real_time() - philo->last_meal;
		printf("result = %d\n", result);
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
	printf("%d %d %s\n", real_time(), philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}
