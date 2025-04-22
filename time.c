/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:55:12 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/22 10:04:36 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	real_time(void)
{
	struct timeval	current_time;
	int							time_seconde;
	int							time_microseconde;

	time_seconde = 0;
	time_microseconde = 0;
	gettimeofday(&current_time, NULL);
	time_seconde = current_time.tv_sec * 1000;
	time_microseconde = current_time.tv_usec / 1000;
	return (time_seconde + time_microseconde);
}

/*
struct timeval {
    time_t      tv_sec;// secondes
    suseconds_t tv_usec;// microsecondes
};
gettimeofday 	int gettimeofday(struct timeval *tv, struct timezone *tz);
*/
