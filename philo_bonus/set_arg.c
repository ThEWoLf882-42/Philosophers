/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:07:41 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 12:10:23 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	set_arg(t_phi *phi, int ac, char **av)
{
	phi->nph = ft_atoi(av[1]);
	phi->td = ft_atoi(av[2]);
	phi->te = ft_atoi(av[3]);
	phi->ts = ft_atoi(av[4]);
	phi->npe = -1;
	if (ac == 6)
		phi->npe = ft_atoi(av[5]);
}
