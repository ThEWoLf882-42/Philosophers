/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:28:48 by agimi             #+#    #+#             */
/*   Updated: 2023/03/28 14:28:48 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks(t_phi	*phi)
{
	pthread_mutex_t	forks[phi->nph];
	int				i;

	i = -1;
	while (++i < phi->nph)
		pthread_mutex_init(&forks[i], NULL);
	phi->fork = forks;
	pthread_mutex_init(&phi->mdead, NULL);
}
