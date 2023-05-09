/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:54 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 11:57:55 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mon(t_phi *phi)
{
	pthread_t		mo;

	if (pthread_create(&mo, NULL, &mon, phi))
	{
		printf("Creation of MON Failed");
		free(phi);
		return (0);
	}
	if (pthread_join(mo, NULL))
	{
		printf("Joining of MON Failed");
		free(phi);
		return (0);
	}
	return (1);
}
