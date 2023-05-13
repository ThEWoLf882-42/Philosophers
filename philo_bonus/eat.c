/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:56:30 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 16:30:12 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_phi	*phi)
{
	sem_wait(phi->print);
	printf("%zu %d is eating\n", now(phi->st), phi->th.id);
	sem_post(phi->print);
}

void	eat(t_phi *phi)
{
	sem_wait(phi->fork);
	sem_wait(phi->fork);
	tfork(phi);
	eating(phi);
	phi->th.le = time_ms();
	phi->th.ec++;
	my_sleep(time_ms(), phi->te);
	sem_post(phi->fork);
	sem_post(phi->fork);
}
