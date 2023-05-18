/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:13:48 by agimi             #+#    #+#             */
/*   Updated: 2023/05/17 19:29:57 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	forking(t_phi	*phi)
{
	int		i;

	i = -1;
	phi->st = time_ms();
	phi->std = phi->st + 10;
	phi->pid = malloc(sizeof(pid_t) * phi->nph);
	while (++i < phi->nph)
	{
		phi->th.id = i + 1;
		phi->pid[i] = fork();
		if (phi->pid[i] == -1)
		{
			murder1(phi, i);
			return (0);
		}
		else if (phi->pid[i] == 0)
		{
			death_checker(phi);
			thread(phi);
		}
	}
	sem_wait(phi->end);
	return (1);
}
