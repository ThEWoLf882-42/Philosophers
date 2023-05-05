/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:43:30 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 10:55:53 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_phi *phi)
{
	int				i;
	pthread_t		th[200];
	pthread_attr_t	dth;
	t_th			*thr;

	i = -1;
	phi->th = NULL;
	pthread_attr_init(&dth);
	pthread_attr_setdetachstate(&dth, PTHREAD_CREATE_DETACHED);
	while (++i < phi->nph)
	{
		thr = new_th(phi, i + 1);
		if (pthread_create(&th[i], &dth, &thread, thr))
			perror("Creation of TH Failed");
	}
}
