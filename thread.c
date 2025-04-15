/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduflot <lduflot@student.42perpignan.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:53:30 by lduflot           #+#    #+#             */
/*   Updated: 2025/04/15 16:15:24 by lduflot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_rules *rules, t_philo *philo)
{
	int	i;

	i = 0;




}
int	pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(start_routine)(void *), void *arg)
{
	
}

//pthread_t *thread 
// = pointeur vers une varialbe qui recoit l'id du thread crée 
// const pthread_attr_t *attr
// = pointeur vers une strcuture du thrrad//void *(start_routine)(void *)
// fonction que le thread va efffectuer , elle sera allo une fois le thread inité, on peut y mettre un return NULL
// void *arg
// = argument a passé a la fonction 
