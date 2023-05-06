/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:26:50 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 17:49:27 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_arg(t_phi *phi, int ac, char **av)
{
	phi->nph = ft_atoi(av[1]);
	phi->td = ft_atoi(av[2]);
	phi->te = ft_atoi(av[3]);
	phi->ts = ft_atoi(av[4]);
	if (ac == 6)
		phi->npe = ft_atoi(av[5]);
	else
		phi->npe = -1;
	phi->done = 0;
	phi->dead = 0;
}
