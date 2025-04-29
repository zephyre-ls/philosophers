/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/29 12:14:15 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_thread(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		pthread_create(&philo[i].thread_id, NULL, start_routine, &philo[i]);
		i++;
	}
	return (0);
}

void	wait_threads_philo(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		pthread_join(philo[i].thread_id, NULL); //mentor qui attend que chaque thread 
		//se termine pour passer au suivant. 
		i++;
	}
}
//pthread_t *thread 
// = pointeur vers une varialbe qui recoit l'id du thread crée 
// const pthread_attr_t *attr
// = pointeur vers une strcuture du thrrad//void *(start_routine)(void *)
// fonction que le thread va efffectuer , elle sera allo une fois le thread inité, on peut y mettre un return NULL
// void *arg
// = argument a passé a la fonction 
