/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:20 by agimi             #+#    #+#             */
/*   Updated: 2023/05/06 13:11:03 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_th *th)
{
	pthread_mutex_lock(&th->phi->mprint);
	printf("%zu %d is eating\n", now(th->st), th->id);
	pthread_mutex_unlock(&th->phi->mprint);
}

void	take_forks(t_th *th)
{
	int				id;
	pthread_mutex_t	*forks;

	id = th->id - 1;
	forks = th->phi->fork;
	if (!(th->id % 2))
	{
		pthread_mutex_lock(&forks[id]);
		forking(th, id);
		pthread_mutex_lock(&forks[(id + 1) % th->phi->nph]);
		forking(th, id);
	}
	else
	{
		pthread_mutex_lock(&forks[(id + 1) % th->phi->nph]);
		forking(th, id);
		pthread_mutex_lock(&forks[id]);
		forking(th, id);
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
	pthread_mutex_lock(&th->phi->mle);
	th->le = time_ms();
	pthread_mutex_unlock(&th->phi->mle);
	eating(th);
	my_sleep(time_ms(), th->phi->te);
	unlock_fork(th);
	pthread_mutex_lock(&th->phi->mec);
	th->ec++;
	pthread_mutex_unlock(&th->phi->mec);
}
