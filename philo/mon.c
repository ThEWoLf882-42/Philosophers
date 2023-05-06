/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mon.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:25:24 by agimi             #+#    #+#             */
/*   Updated: 2023/05/06 12:37:24 by agimi            ###   ########.fr       */
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
				died(phi, th);
				phi->dead = 1;
				free(phi);
				return (NULL);
			}
			th = th->next;
		}
		th = phi->th;
	}
	free(phi);
	return (NULL);
}
