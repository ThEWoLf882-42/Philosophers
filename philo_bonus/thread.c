/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:42:15 by agimi             #+#    #+#             */
/*   Updated: 2023/05/17 16:53:23 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thread(t_phi *phi)
{
	while (time_ms() < phi->std)
		usleep(phi->td);
	thinking(phi);
	while (1)
	{
		if (phi->th.ec == phi->npe)
			sem_post(phi->sec);
		eat(phi);
		sleeping(phi);
		thinking(phi);
	}
}
