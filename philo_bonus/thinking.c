/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 14:08:04 by agimi             #+#    #+#             */
/*   Updated: 2023/05/18 22:29:42 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thinking(t_phi *phi)
{
	sem_wait(phi->print);
	printf("%zu %d is thinking\n", now(phi->std), phi->th.id);
	sem_post(phi->print);
}
