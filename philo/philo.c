/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:25:38 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 11:36:54 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_phi	*phi;

	if (ac == 5 || ac == 6)
	{
		phi = malloc(sizeof(t_phi));
		set_arg(phi, ac, av);
		set_forks(phi);
		create_thread(phi);
		create_mon(phi);
	}
	else
		printf("Please enter 4/5 Argument\n");
	pthread_exit(0);
}
