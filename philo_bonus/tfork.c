/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:58:48 by agimi             #+#    #+#             */
/*   Updated: 2023/05/17 15:39:08 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	tfork(t_phi	*phi)
{
	sem_wait(phi->print);
	printf("%ld %d has taken a fork\n", now(phi->std), phi->th.id);
	printf("%ld %d has taken a fork\n", now(phi->std), phi->th.id);
	sem_post(phi->print);
}
