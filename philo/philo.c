/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:25:38 by agimi             #+#    #+#             */
/*   Updated: 2023/05/07 16:39:28 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_phi	*phi;

	if (ac == 5 || ac == 6)
	{
		phi = malloc(sizeof(t_phi));
		if (!check_arg(av))
		{
			free(phi);
			return (0);
		}
		set_arg(phi, ac, av);
		set_forks(phi);
		if (!create_thread(phi))
		{
			free(phi);
			return (0);
		}
		if (!create_mon(phi))
		{
			free(phi);
			return (0);
		}
	}
	else
		printf("Please enter 4/5 Argument\n");
}
