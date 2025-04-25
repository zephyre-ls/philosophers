/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:55:12 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/25 10:17:02 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	real_time()
{
	struct timeval	current_time;
	int							time_seconde;
	int							time_microseconde;
	int							time_ms;

	gettimeofday(&current_time, NULL);
	time_seconde = current_time.tv_sec * 1000;
	time_microseconde = current_time.tv_usec / 1000;
	time_ms = time_seconde + time_microseconde;
	return (time_ms);
}

/*
struct timeval {
    time_t      tv_sec;// secondes
    suseconds_t tv_usec;// microsecondes
};
gettimeofday 	int gettimeofday(struct timeval *tv, struct timezone *tz);
*/
