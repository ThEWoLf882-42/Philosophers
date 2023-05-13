/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:07:05 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 16:24:14 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_check(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	while (1)
	{
		if (now(phi->th.le) > (size_t)phi->td)
		{
			sem_wait(phi->print);
			printf("%zu %d died\n", now(phi->st), phi->th.id);
			sem_post(phi->end);
			exit(0);
		}
	}
	return (NULL);
}

void	death_checker(t_phi *phi)
{
	phi->th.le = time_ms();
	if (pthread_create(&phi->checker, NULL, &death_check, phi))
	{
		printf("Creation of Checker D Failed\n");
		sem_post(phi->end);
	}
	pthread_detach(phi->checker);
}
