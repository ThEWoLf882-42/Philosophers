/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:07:05 by agimi             #+#    #+#             */
/*   Updated: 2023/05/17 16:49:50 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*death_check(void *arg)
{
	t_phi	*phi;

	phi = (t_phi *)arg;
	while (time_ms() < phi->std)
		usleep(phi->std);
	while (1)
	{
		if ((int)now(phi->th.le) >= phi->td)
		{
			sem_wait(phi->print);
			printf("%zu %d died\n", now(phi->std), phi->th.id);
			sem_post(phi->end);
			exit(0);
		}
		my_sleep(time_ms(), (phi->td - now(phi->th.le)));
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
