/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:54 by agimi             #+#    #+#             */
/*   Updated: 2023/05/07 16:39:45 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mon(t_phi *phi)
{
	pthread_t		mo;

	if (pthread_create(&mo, NULL, &mon, phi))
	{
		printf("Creation of MON Failed");
		return (0);
	}
	if (pthread_join(mo, NULL))
	{
		printf("Joining of MON Failed");
		return (0);
	}
	return (1);
}
