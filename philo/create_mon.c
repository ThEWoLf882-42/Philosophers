/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:54 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 17:41:31 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mon(t_phi *phi)
{
	pthread_t		mo;

	if (pthread_create(&mo, NULL, &mon, phi))
		perror("Creation of MON Failed");
	if (pthread_join(mo, NULL))
		perror("Joining of MON Failed");
}
