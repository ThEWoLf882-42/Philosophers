/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:12:37 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 15:05:27 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	set_forks(t_phi	*phi)
{
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/end");
	sem_unlink("/ec");
	phi->fork = sem_open("/fork", O_CREAT, 0644, phi->nph);
	phi->print = sem_open("/print", O_CREAT, 0644, 1);
	phi->end = sem_open("/end", O_CREAT, 0644, 0);
	phi->sec = sem_open("/ec", O_CREAT, 0644, 0);
	if (phi->fork == SEM_FAILED || phi->print == SEM_FAILED
		|| phi->end == SEM_FAILED || phi->sec == SEM_FAILED)
	{
		free(phi);
		return (0);
	}
	if (!eat_checker(phi))
	{
		free(phi);
		return (0);
	}
	return (1);
}
