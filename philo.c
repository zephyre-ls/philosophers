/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:34 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/01 15:55:30 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* A  gerer:
* leaks quand on interromp le programme; => non corrigeable 
* parsing ne fonctionne plus et meme si mauvais argument progamm se lance => OK
* gestion de l'option nbr de repas 
* mon temps apparait en négatif : POURQUOOOOOOI ?
*/

void	free_mutex(t_philo *philo, t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nbr_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print_mutex);
	pthread_mutex_destroy(&rules->death_mutex);
	pthread_mutex_destroy(&rules->meal_empty_mutex);
	free(philo);
	free(rules->forks);
}

int	main(int argc, char **argv)
{
	t_rules	rules;
	t_philo	*philo;

	if (parsing_args(argc, argv))
		return (1);
	init_argv(&rules, argv);
	philo = malloc(sizeof(t_philo) * rules.nbr_philo);
	if (!philo)
		return (1);
	rules.forks = malloc(sizeof(pthread_mutex_t) * rules.nbr_philo);
	if (!rules.forks)
	{
		free(philo);
		return (1);
	}
	init_philo_fork(&rules, philo);
	init_mutex(&rules);
	init_meal(&rules, philo);
	create_thread(philo, &rules);
	wait_threads_philo(philo, &rules);
	free_mutex(philo, &rules);
	return (0);
}
