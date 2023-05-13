/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:58:48 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 14:24:43 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	tfork(t_phi	*phi)
{
	sem_wait(phi->print);
	printf("%zu %d has taken a fork\n", now(phi->st), phi->th.id);
	printf("%zu %d has taken a fork\n", now(phi->st), phi->th.id);
	sem_post(phi->print);
}
