/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:01:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/08/09 19:38:31 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
Cas pour 1 philosopher
*/
void	only_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
	print_state_philo(philo, "has taken a fork");
	print_state_philo(philo, "is thinking");
	usleep(philo->rules->time_to_die * 1000);
	print_state_philo(philo, "is died");
	pthread_mutex_unlock(&philo->rules->forks[philo->left_fork_id]);
	pthread_mutex_lock(&philo->rules->end_simulation_mutex);
	philo->rules->is_dead_end_simulation = 1;
	pthread_mutex_unlock(&philo->rules->end_simulation_mutex);
}

/*
Thread monitor: surveille mort, end_simulation
*/
void	*start_monitoring(void *arg)
{
	t_rules	*rules;
	int		i;
	int		status;

	rules = (t_rules *)arg;
	while (!end_simulation(rules->philo))
	{
		i = 0;
		while (i < rules->nbr_philo)
		{
			pthread_mutex_lock(&rules->meal_mutex);
			status = (rules->philo_finish == rules->nbr_philo);
			pthread_mutex_unlock(&rules->meal_mutex);
			if (death_or_not_death(&rules->philo[i]) || status)
			{
				pthread_mutex_lock(&rules->end_simulation_mutex);
				rules->is_dead_end_simulation = 1;
				pthread_mutex_unlock(&rules->end_simulation_mutex);
				break ;
			}
			i++;
		}
		ft_usleep(1000);
	}
	return (NULL);
}

/*
Routine pour tous les philosophers
*/
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
	print_state_philo(philo, "is eating");
	ft_usleep(philo->rules->time_to_eat);
	if (count_meal(philo) == 1)
		return (1);
	unlock_thread(philo);
	print_state_philo(philo, "is sleeping");
	ft_usleep(philo->rules->time_to_sleep);
	return (0);
}

/*
Attribution des fork pour eviter le Deadlocks;
Chaque philo à une fork droite/gauche
Alterne l'ordre de prise:
Philo.id.pair = prend left puis right
Philo.id.impair = prend right puis left
*/
void	take_forks(t_philo *philo)
{
	print_state_philo(philo, "is thinking");
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
		print_state_philo(philo, "has taken a fork");
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
		print_state_philo(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->rules->forks[philo->right_fork_id]);
		print_state_philo(philo, "has taken a fork");
		pthread_mutex_lock(&philo->rules->forks[philo->left_fork_id]);
		print_state_philo(philo, "has taken a fork");
	}
}
