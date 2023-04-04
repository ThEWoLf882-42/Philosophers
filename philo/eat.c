/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:20 by agimi             #+#    #+#             */
/*   Updated: 2023/04/04 15:07:20 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_th *th)
{
	int				id;
	pthread_mutex_t *forks;

	id = th->id - 1;
	forks = th->phi->fork;
	if(!(id % 2))
	{
		pthread_mutex_lock(&forks[id]);
		pthread_mutex_lock(&forks[(id + 1) % th->phi->nph]);
		// printf("%lld %d has taken a fork %d\n", now(th->st), id + 1, id);
		// printf("%lld %d has taken a fork %d\n", now(th->st), id + 1, (id + 1) % th->phi->nph);
	}
	else
	{
		pthread_mutex_lock(&forks[(id + 1) % th->phi->nph]);
		pthread_mutex_lock(&forks[id]);
		// printf("%lld %d has taken a fork %d\n", now(th->st), id + 1, (id + 1) % th->phi->nph);
		// printf("%lld %d has taken a fork %d\n", now(th->st), id + 1, id);
	}
}

void	unlock_fork(t_th *th)
{
	int				id;
	pthread_mutex_t *forks;

	id = th->id - 1;
	forks = th->phi->fork;
	pthread_mutex_unlock(&forks[id]);
	pthread_mutex_unlock(&forks[(id + 1) % th->phi->nph]);
}

void	eat(t_th *th)
{
	take_fork(th);
	printf("%lld %d is eating\n", now(th->st), th->id);
	my_sleep(th->phi->te);
	// usleep(th->phi->te * 1000);
	th->le = time_ms();
	unlock_fork(th);
}