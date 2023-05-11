/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:25:24 by agimi             #+#    #+#             */
/*   Updated: 2023/05/10 12:57:53 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	tdone(t_phi *phi)
{
	pthread_mutex_lock(&phi->mdone);
	if (phi->done == phi->nph)
	{
		pthread_mutex_unlock(&phi->mdone);
		return (1);
	}
	pthread_mutex_unlock(&phi->mdone);
	return (0);
}

int	sded(t_phi *phi, t_th *th)
{
	pthread_mutex_lock(&phi->mec[th->i]);
	if (th->ec != th->phi->npe)
	{
		pthread_mutex_lock(&phi->mle[th->i]);
		if (now(th->le) > (size_t)phi->td)
		{
			died(phi, th);
			pthread_mutex_lock(&phi->mdead);
			phi->dead = 1;
			pthread_mutex_unlock(&phi->mdead);
			pthread_mutex_unlock(&phi->mec[th->i]);
			pthread_mutex_unlock(&phi->mle[th->i]);
			return (1);
		}
		pthread_mutex_unlock(&phi->mle[th->i]);
	}
	pthread_mutex_unlock(&phi->mec[th->i]);
	return (0);
}

void	*mon(void *arg)
{
	t_phi	*phi;
	t_th	*th;

	phi = (t_phi *)arg;
	th = phi->th;
	while (1)
	{
		if (tdone(phi))
			break ;
		while (th)
		{
			if (sded(phi, th))
				return (NULL);
			th = th->next;
		}
		th = phi->th;
	}
	return (NULL);
}
