/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:28:48 by agimi             #+#    #+#             */
/*   Updated: 2023/05/07 19:24:18 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks(t_phi	*phi)
{
	int				i;

	i = -1;
	while (++i < phi->nph)
	{
		pthread_mutex_init(&phi->fork[i], NULL);
		pthread_mutex_init(&phi->mec[i], NULL);
		pthread_mutex_init(&phi->mle[i], NULL);
	}
	pthread_mutex_init(&phi->mdone, NULL);
	pthread_mutex_init(&phi->mprint, NULL);
	pthread_mutex_init(&phi->mdead, NULL);
}
