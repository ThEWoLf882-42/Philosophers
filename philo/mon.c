/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:25:24 by agimi             #+#    #+#             */
/*   Updated: 2023/04/05 16:25:24 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*mon(void *arg)
{
	t_phi	*phi;
	t_th	*th;

	phi = (t_phi *)arg;
	th = phi->th;
	while (phi->done != phi->nph)
	{
		while (th)
		{
			if (now(th->le) > (size_t)phi->td && (th->ec != th->phi->npe))
			{
				pthread_mutex_lock(&phi->mprint);
				printf("%lld %d died\n", now(th->st), th->id);
				pthread_mutex_unlock(&phi->mprint);
				phi->dead = 1;
				exit(0);
			}
			th = th->next;
		}
		th = phi->th;
	}
	return (NULL);
}