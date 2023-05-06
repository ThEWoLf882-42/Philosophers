/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:25:38 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 17:36:37 by agimi            ###   ########.fr       */
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
}
