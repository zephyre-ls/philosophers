/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:34 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/15 15:51:48 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	j;

	j = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[j])
		{
			if (only_number(argv[j]) || ft_atoi(argv[j]) <= 0)
			{
				printf("Erreur: Veuillez entrer un nbr > 0\n");
				return (1);
			}
			j++;
		}
		error_nbr_philo(argv[1]);
	}
	else
	{
		printf("./philo nbr_philo, time_to_die, time_to_eat, time_to_sleep, \
		number_of_times_each_philosopher_must_eat (time en millieconde)\n");
		return (1);
	}
	return (0);
}
