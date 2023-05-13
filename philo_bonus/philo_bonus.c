/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:48:59 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 13:21:52 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_phi	*phi;

	if (ac == 5 || ac == 6)
	{
		phi = malloc(sizeof(t_phi));
		if (!check_arg(av, phi))
			return (1);
		set_arg(phi, ac, av);
		if (!set_forks(phi))
			return (1);
		if (!forking(phi))
		{
			free(phi);
			return (1);
		}
	}
	else
		printf("Please enter 4/5 Argument\n");
}
