/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:43:30 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 11:59:49 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_thread(t_phi *phi)
{
	int				i;
	pthread_t		th[200];
	t_th			*thr;

	i = -1;
	phi->th = NULL;
	while (++i < phi->nph)
	{
		thr = new_th(phi, i + 1);
		if (pthread_create(&th[i], NULL, &thread, thr))
		{
			printf("Creation of TH Failed");
			the_free(phi);
			return (0);
		}
		pthread_detach(th[i]);
	}
	return (1);
}
