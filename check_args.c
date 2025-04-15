/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:42 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/15 15:49:21 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *arg)
{
	int		i;
	long	nbr;

	i = 0;
	nbr = 0;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		nbr = nbr * 10 + (arg[i] - '0');
		if (nbr > INT_MAX)
		{
			printf("Erreur : Valeure supérieur à INT_MAX repéré\n");
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
		printf("Erreur: Minimum deux philosophers requis\n");
		return (1);
	}
	return (0);
}
