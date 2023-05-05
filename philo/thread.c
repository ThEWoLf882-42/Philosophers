/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:48:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 12:35:07 by agimi            ###   ########.fr       */
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
		sleeping(th);
		my_sleep(time_ms(), th->phi->ts);
		think(th);
		my_sleep(time_ms(), 1);
	}
	if (th->ec == th->phi->npe)
	{
		pthread_mutex_lock(&th->phi->mdone);
		th->phi->done++;
		pthread_mutex_unlock(&th->phi->mdone);
	}
	free(th);
	return (NULL);
}
