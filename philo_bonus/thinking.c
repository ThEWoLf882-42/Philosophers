/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:08:04 by agimi             #+#    #+#             */
/*   Updated: 2023/05/17 17:05:17 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thinking1(t_phi *phi)
{
	sem_wait(phi->print);
	printf("0 %d is thinking\n", phi->th.id);
	sem_post(phi->print);
}

void	thinking(t_phi *phi)
{
	sem_wait(phi->print);
	printf("%zu %d is thinking\n", now(phi->std), phi->th.id);
	sem_post(phi->print);
}
