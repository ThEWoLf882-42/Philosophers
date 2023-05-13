/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:42:15 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 16:46:32 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thread(t_phi *phi)
{
	phi->st = time_ms();
	thinking(phi);
	while (1)
	{
		eat(phi);
		sleeping(phi);
		if (phi->th.ec == phi->npe)
			sem_post(phi->sec);
		thinking(phi);
	}
}

