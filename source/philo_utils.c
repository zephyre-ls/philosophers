/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:49:31 by lduflot           #+#    #+#             */
/*   Updated: 2025/05/12 11:43:20 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *str)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		if (nbr > INT_MAX)
		{
			printf("Erreur : Valeure supérieur à INT_MAX\n");
			return (1);
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
			printf("Erreur: Number Invalid\n");
			return (1);
		}
	}
	return (0);
}

int	parsing_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("./philo number_philo, time_to_die, time_to_eat, time_to_sleep, \
		optionnal: number_of_meal\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (only_number(argv[i]) || ft_atoi(argv[i]) <= 0)
		{
			printf("Erreur: Argument invalid\n");
			return (1);
		}
		i++;
	}
	return (0);
}
