/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:34 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/25 11:09:44 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	j;
	t_rules	rules;
	t_philo	*philo;

	j = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[j])
		{
			if (only_number(argv[j]))
				return (1);
			j++;
		}
		init_argv(&rules, argv);
		philo = malloc(sizeof(t_philo) * rules.nbr_philo);
		rules.forks = malloc(sizeof(pthread_mutex_t) * rules.nbr_philo);
		init_mutex(&rules);
		init_philo_fork(&rules, philo);
		create_thread(philo, &rules);
	//	printf("Temps actuel (ms) : %d\n", real_time());
	}
	else
	{
		printf("./philo nbr_philo, time_to_die, time_to_eat, time_to_sleep, \
		number_of_times_each_philosopher_must_eat (time en millieconde)\n");
		return (1);
	}
	return (0);
}
