/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   murder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:11:27 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 16:27:06 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	murder1(t_phi *phi, int i)
{
	while (--i >= 0)
		kill(phi->pid[i], SIGKILL);
}

void	murder2(t_phi *phi)
{
	int	i;

	i = -1;
	while (++i < phi->nph)
		kill(phi->pid[i], SIGKILL);
}
