/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/25 11:14:59 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;

	while (1)
	{
		/*if ((real_time() - philo->last_meal) > (philo->last_meal > philo->rules->time_to_die))
		{
			pthread_mutex_lock(&philo->rules->death_mutex);
			printf("%d died 💀\n", philo->id);
			pthread_mutex_unlock(&philo->rules->death_mutex);
			break;
		}*/
		if (philo->id %2 == 0) //ordre pair pour la prise des forks. evite deadlock
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
		usleep(philo->rules->time_to_sleep);
		pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
		pthread_mutex_unlock(&philo->rules->forks[philo->right_fork_id]);
		printf("%d a poser les 2 fork\n", philo->id);
		usleep(1000);
		print_state_philo(philo,"is sleeping 💤");
		usleep(philo->rules->time_to_sleep);
		print_state_philo(philo,"is thinking 🤔");
		usleep(1000);
	}
	return (0);
}

void	print_state_philo(t_philo *philo, char *txt)
{
	pthread_mutex_lock(&philo->rules->print_mutex);
	printf("%d %d %s\n", real_time(), philo->id, txt);
	pthread_mutex_unlock(&philo->rules->print_mutex);
}

/*char	print_state_philo(t_philo *philo)
{
	printf(real_time(), "%d has taken a fork 🍴\n", philo->thread_id);
	printf(real_time(), "%d is eating 🍝\n", philo->thread_id);
	printf(real_time(), "%d is sleeping 💤\n", philo->thread_id);
	printf(real_time(), "%d is thinking 🤔\n", philo->thread_id);
	printf(real_time(), "%d died 💀\n", philo->thread_id);
}*/
