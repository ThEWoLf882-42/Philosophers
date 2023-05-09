/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:48:59 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 12:11:53 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_phi	*phi;

	if (ac == 5 || ac == 6)
	{
		phi = malloc(sizeof(t_phi));
		if (!!check_arg(av, phi))
			return (1);
		set_arg(phi, ac, av);
		set_forks(phi);
	}
	else
		printf("Please enter 4/5 Argument\n");
}
