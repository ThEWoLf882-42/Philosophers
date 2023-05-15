/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:08:04 by agimi             #+#    #+#             */
/*   Updated: 2023/05/15 16:11:50 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thinking(t_phi *phi)
{
	sem_wait(phi->print);
	printf("%ld %d is thinking\n", now(phi->st), phi->th.id);
	sem_post(phi->print);
}
