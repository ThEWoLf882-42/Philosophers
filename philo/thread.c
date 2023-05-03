/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:48:25 by agimi             #+#    #+#             */
/*   Updated: 2023/03/28 14:48:25 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread(void *arg)
{
	t_th	*th;

	th = (t_th *)arg;
	th->st = time_ms();
	th->le = th->st;
	if (!(th->id % 2))
		my_sleep(time_ms(), th->phi->te / 2);
	while (th->ec != th->phi->npe && !th->phi->dead)
	{
		eat(th);
		pthread_mutex_lock(&th->phi->mprint);
		printf("%lld %d is sleeping\n", now(th->st), th->id);
		pthread_mutex_unlock(&th->phi->mprint);
		my_sleep(time_ms(), th->phi->ts);
		pthread_mutex_lock(&th->phi->mprint);
		printf("%lld %d is thinking\n", now(th->st), th->id);
		pthread_mutex_unlock(&th->phi->mprint);
		my_sleep(time_ms(), 1);
	}
	if (th->ec == th->phi->npe)
	{
		pthread_mutex_lock(&th->phi->mdone);
		th->phi->done++;
		pthread_mutex_unlock(&th->phi->mdone);
	}
	return (NULL);
}
