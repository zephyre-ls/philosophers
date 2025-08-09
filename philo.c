/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:34 by lduflot           #+#    #+#             */
/*   Updated: 2025/08/09 19:43:06 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Philosophers
__________
Thread : sous process, exe en parrallèle, partage le même espace memoire
Dans philo: 1 thread monitor et chaque philo est un thread
___________
Mutex (mutual exclusion) : verouille une ressource pour qu'un seul thread y
accède à la fois.
___________
Starvation (famine) : Si les ressources sont toujours prise par les autres,
le philo peut ne jamais manger
___________
Deadlock (interblocage) : bloqué avec une fourchette, par de unlock, mauvaise
répartition des ressources
___________
Data race : Deux threads accédent à la même var sans protection.
Corrigé en protégeant lecture/écriture par des mutex
*/

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
	rules.philo = philo;
	create_thread(philo, &rules);
	wait_threads_philo(philo, &rules);
	free_mutex(philo, &rules);
	return (0);
}

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
	pthread_mutex_destroy(&rules->last_meal_mutex);
	pthread_mutex_destroy(&rules->meal_mutex);
	free(philo);
	free(rules->forks);
}
