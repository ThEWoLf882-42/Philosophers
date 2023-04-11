/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:54 by agimi             #+#    #+#             */
/*   Updated: 2023/04/05 16:19:54 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mon(t_phi *phi)
{
	pthread_t		mo;
	pthread_attr_t	dmo;

	pthread_attr_init(&dmo);
	pthread_attr_setdetachstate(&dmo, PTHREAD_CREATE_DETACHED);
	if (pthread_create(&mo, &dmo, &mon, phi))
			perror("Creation of MON Failed");
}