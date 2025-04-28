/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:29:37 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/28 08:54:40 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	death_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->death_mutex);
	print_state_philo(philo, "is died 💀\n");
	pthread_mutex_unlock(&philo->rules->death_mutex);
}
