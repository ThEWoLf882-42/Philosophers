/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:12:37 by agimi             #+#    #+#             */
/*   Updated: 2023/05/10 19:13:05 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	set_forks(t_phi	*phi)
{
	sem_unlink("/fork");
	phi->fork = sem_open("/fork", O_CREAT, 0644, phi->nph);
	if (phi->fork == SEM_FAILED)
	{
		free(phi);
		return (0);
	}
	return (1);
}
