/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:30:16 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 16:21:24 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*eat_check(void *arg)
{
	t_phi	*phi;
	int		i;

	phi = (t_phi *)arg;
	i = -1;
	sem_wait(phi->print);
	while (++i < phi->nph)
	{
		sem_post(phi->print);
		sem_wait(phi->sec);
		sem_wait(phi->print);
	}
	sem_post(phi->end);
	return (NULL);
}

int	eat_checker(t_phi *phi)
{
	if (phi->npe > 0)
	{
		if (pthread_create(&phi->checker, NULL, &eat_check, phi))
		{
			printf("Creation of Checker E Failed\n");
			return (0);
		}
		pthread_detach(phi->checker);
	}
	return (1);
}
