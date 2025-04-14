/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:01:34 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/14 14:36:11 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*- Nbr d'arg < 6 = erreur ou 5 si le non optionnel n'estp as mis OK
- Nbr de philo = 1 (pas assez de fork pour qu'il mange, donc au lieu d'utiliser ses mains il va mourir)
- Pas de nbr negatif, pas de float. int max ? OK ?*/

int	ft_atoi(char *arg)
{
	int	i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		nbr = nbr * 10 + (arg[i] - '0');
		if (nbr > 2147483647)
		{
			printf("Erreur : Valeure supérieur à INT_MAX repéré\n");
			return(1);
		}
		i++;
	}
	return (nbr);
}

int	only_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
			if (argv[i] >= '0' && argv[i] <= '9')
				i++;
			else
			{
				printf("Erreur: Veuillez rentrer un nombre valable\n");
				return (1);
			}
	}
	return (0);
}

int	error_nbr_philo(char *argv)
{
	int	nbr_philosophers;
	
	nbr_philosophers = ft_atoi(argv);
	if (nbr_philosophers < 2)
	{
		printf("Erreur: Minimum deux philosophers requis pour bénéficier de deux forks\n"); 
		return(1);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int	j;

	j = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[j])
		{
			if (only_number(argv[j]) || ft_atoi(argv[j]) <= 0)
				return (1);
			j++;
		}
		if (error_nbr_philo(argv[1]) != 0)
			return (1);
		if (argv[1] == 0 || argv[2] == 0 || argv[3] == 0 || argv[4] == 0 || argv[5] == 0)
		{
			printf("Erreur: Veuillez entrer un nbr > 0\n");
			return (1);
		}
	}
	else
	{
		printf("./philo nbr_philo, time_to_die, time_to_eat, time_to_sleep, number_of_times_each_philosopher_must_eat (time en millieconde)\n");
		return (1);
	}
	return (0);
}
