/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:13:48 by agimi             #+#    #+#             */
/*   Updated: 2023/05/10 19:43:21 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	forking(t_phi	*phi)
{
	int		i;

	i = -1;
	phi->pid = malloc(sizeof(pid_t) * phi->nph);
	while (++i < phi->nph)
	{
		phi->pid[i] = fork();
		if (phi->pid[i] != 0)
			printf("pid[%d]: %d\n", i, phi->pid[i]);
	}
	pause();
}
