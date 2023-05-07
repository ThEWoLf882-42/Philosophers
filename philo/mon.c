/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:25:24 by agimi             #+#    #+#             */
/*   Updated: 2023/05/06 19:06:38 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sded(t_phi *phi, t_th *th)
{
	pthread_mutex_lock(&phi->mec);
	if (th->ec != th->phi->npe)
	{
		pthread_mutex_lock(&phi->mle);
		if (now(th->le) > (size_t)phi->td)
		{
			died(phi, th);
			pthread_mutex_lock(&phi->mdead);
			phi->dead = 1;
			pthread_mutex_unlock(&phi->mdead);
			pthread_mutex_unlock(&phi->mec);
			pthread_mutex_unlock(&phi->mle);
			return (1);
		}
		pthread_mutex_unlock(&phi->mle);
	}
	pthread_mutex_unlock(&phi->mec);
	return (0);
}

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
			if (sded(phi, th))
			{
				free (phi);
				return (NULL);
			}
			th = th->next;
		}
		th = phi->th;
	}
	free(phi);
	return (NULL);
}
