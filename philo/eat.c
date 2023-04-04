/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:07:20 by agimi             #+#    #+#             */
/*   Updated: 2023/04/04 15:07:20 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_th *th)
{
	int	id;

	id = th->id;
	pthread_mutex_lock(&th->phi->fork[id]);
	// printf("fork id: %d id: %d\n", (id), id);
	// printf("%lld %d has taken a fork\n", now(th->st), id);
	// pthread_mutex_lock(&th->phi->fork[(id + 1) % th->phi->nph]);
	// printf("fork id: %d id: %d\n", ((id + 1) % th->phi->nph), id);
	// printf("%lld %d has taken a fork\n", now(th->st), id);
}

void	eat(t_th *th)
{
	take_fork(th);
	// printf("%lld %d is eating\n", now(th->st), th->id);
	// my_sleep(th->phi->te);
	// th->le = time_ms();
}