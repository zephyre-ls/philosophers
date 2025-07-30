/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:49:31 by lduflot           #+#    #+#             */
/*   Updated: 2025/07/30 08:49:01 by lduflot          ###   ########.fr       */
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
			write(2, "Value > INT_MAX ! ", 18);
			return (-1);
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
			write(2, "Number positif only ! ", 23);
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
		write(2, "./philo number_philo, time_to_die, \
time_to_eat, time_to_sleep, optionnal: number_of_meal\n", 90);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (only_number(argv[i]))
		{
			write(2, "Error: Number Invalid\n", 23);
			return (1);
		}
		if (ft_atoi(argv[i]) <= 0)
		{
			write(2, "Error: Arugment invalid\n", 25);
			return (1);
		}
		i++;
	}
	return (0);
}
