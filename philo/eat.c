/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:20 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 16:54:25 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_th *th)
{
	int				id;
	pthread_mutex_t	*forks;

	id = th->id - 1;
	forks = th->phi->fork;
	if (!(th->id % 2))
	{
		pthread_mutex_lock(&forks[id]);
		pthread_mutex_lock(&th->phi->mprint);
		printf("%zu %d has taken a fork\n", now(th->st), id + 1);
		pthread_mutex_unlock(&th->phi->mprint);
		pthread_mutex_lock(&forks[(id + 1) % th->phi->nph]);
		pthread_mutex_lock(&th->phi->mprint);
		printf("%zu %d has taken a fork\n", now(th->st), id + 1);
		pthread_mutex_unlock(&th->phi->mprint);
	}
	else
	{
		pthread_mutex_lock(&forks[(id + 1) % th->phi->nph]);
		pthread_mutex_lock(&th->phi->mprint);
		printf("%zu %d has taken a fork\n", now(th->st), id + 1);
		pthread_mutex_unlock(&th->phi->mprint);
		pthread_mutex_lock(&forks[id]);
		pthread_mutex_lock(&th->phi->mprint);
		printf("%zu %d has taken a fork\n", now(th->st), id + 1);
		pthread_mutex_unlock(&th->phi->mprint);
	}
}

void	unlock_fork(t_th *th)
{
	int				id;
	pthread_mutex_t	*forks;

	id = th->id - 1;
	forks = th->phi->fork;
	pthread_mutex_unlock(&forks[id]);
	pthread_mutex_unlock(&forks[(id + 1) % th->phi->nph]);
}

void	eat(t_th *th)
{
	take_forks(th);
	th->le = time_ms();
	pthread_mutex_lock(&th->phi->mprint);
	printf("%zu %d is eating\n", now(th->st), th->id);
	pthread_mutex_unlock(&th->phi->mprint);
	my_sleep(time_ms(), th->phi->te);
	unlock_fork(th);
	th->ec++;
}
