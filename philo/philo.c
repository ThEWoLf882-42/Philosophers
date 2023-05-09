/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:25:38 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 11:58:56 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_phi	*phi;

	if (ac == 5 || ac == 6)
	{
		phi = malloc(sizeof(t_phi));
		if (!check_arg(av, phi))
			return (1);
		set_arg(phi, ac, av);
		set_forks(phi);
		if (!create_thread(phi))
			return (1);
		if (!create_mon(phi))
			return (1);
		the_free(phi);
	}
	else
		printf("Please enter 4/5 Argument\n");
}
