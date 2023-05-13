/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:42:15 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 16:32:42 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thread(t_phi *phi)
{
	phi->st = time_ms();
	while (1)
	{
		thinking(phi);
		eat(phi);
		sleeping(phi);
		thinking(phi);
		usleep(10);
		if (phi->th.ec == phi->npe)
		{
			sem_post(phi->sec);
			exit(0);
		}
	}
}

