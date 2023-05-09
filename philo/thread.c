/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:48:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/08 12:32:33 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	done(t_th *th)
{
	pthread_mutex_lock(&th->phi->mec[th->i]);
	if (th->ec == th->phi->npe)
	{
		pthread_mutex_lock(&th->phi->mdone);
		th->phi->done++;
		pthread_mutex_unlock(&th->phi->mdone);
		pthread_mutex_unlock(&th->phi->mec[th->i]);
	}
	pthread_mutex_unlock(&th->phi->mec[th->i]);
}

int	tec(t_th *th)
{
	pthread_mutex_lock(&th->phi->mec[th->i]);
	if (th->ec == th->phi->npe)
	{
		pthread_mutex_unlock(&th->phi->mec[th->i]);
		return (1);
	}
	pthread_mutex_unlock(&th->phi->mec[th->i]);
	return (0);
}

int	tdead(t_th *th)
{
	pthread_mutex_lock(&th->phi->mdead);
	if (th->phi->dead)
	{
		pthread_mutex_unlock(&th->phi->mdead);
		return (1);
	}
	pthread_mutex_unlock(&th->phi->mdead);
	return (0);
}

void	*thread(void *arg)
{
	t_th	*th;

	th = (t_th *)arg;
	th->st = time_ms();
	pthread_mutex_lock(&th->phi->mle[th->i]);
	th->le = th->st;
	pthread_mutex_unlock(&th->phi->mle[th->i]);
	if (!(th->id % 2))
		my_sleep(time_ms(), th->phi->te / 2);
	while (1)
	{
		if (tdead(th))
			break ;
		if (tec(th))
			break ;
		eat(th);
		sleeping(th);
		my_sleep(time_ms(), th->phi->ts);
		think(th);
		usleep(250);
	}
	done(th);
	return (NULL);
}
