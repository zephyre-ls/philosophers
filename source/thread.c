/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/11 13:16:29 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
	* pthread create
	* *thread = pointeur vers une variable qui recoit l'id du thread crée
	* const pthread_attr_t *attr = pointeur vers struct du thread (NULL)
	* *(start_routine)(void *) = fct que le thread va effectué
	* void *arg = arg a passé a la fonction
	*/

int	create_thread(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, start_routine, &philo[i]);
		i++;
	}
	pthread_create(&rules->monitor_death_thread, NULL, start_monitoring, rules);
	return (0);
}

void	wait_threads_philo(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		pthread_join(philo[i].thread_id, NULL);
		i++;
	}
	pthread_join(rules->monitor_death_thread, NULL);
}
