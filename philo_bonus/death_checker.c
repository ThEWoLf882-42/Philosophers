/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:07:05 by agimi             #+#    #+#             */
/*   Updated: 2023/05/18 21:49:16 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_check(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	usleep(((phi->std - time_ms()) + phi->te / 2) * 1000);
	while (1)
	{
		if ((int)now(phi->th.le) >= phi->td)
		{
			sem_wait(phi->print);
			printf("%zu %d died\n", now(phi->std), phi->th.id);
			sem_post(phi->end);
			exit(0);
		}
		usleep((phi->td - now(phi->th.le)) * 1000);
	}
	return (NULL);
}

void	death_checker(t_phi *phi)
{
	phi->th.le = phi->std;
	if (pthread_create(&phi->th.checker, NULL, &death_check, phi))
	{
		printf("Creation of Checker D Failed\n");
		sem_post(phi->end);
	}
	pthread_detach(phi->checker);
}
