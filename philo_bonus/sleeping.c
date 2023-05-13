/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:07:05 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 14:23:45 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	sleeping(t_phi *phi)
{
	sem_wait(phi->print);
	printf("%zu %d is sleeping\n", now(phi->st), phi->th.id);
	sem_post(phi->print);
	my_sleep(time_ms(), phi->ts);
}
