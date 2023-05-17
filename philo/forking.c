/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:30:09 by agimi             #+#    #+#             */
/*   Updated: 2023/05/16 10:53:50 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forking(t_th *th, int id)
{
	pthread_mutex_lock(&th->phi->mdead);
	if (!th->phi->dead)
	{
		pthread_mutex_lock(&th->phi->mprint);
		printf("%zu %d has taken a fork\n", now(th->st), id + 1);
		pthread_mutex_unlock(&th->phi->mprint);
	}
	pthread_mutex_unlock(&th->phi->mdead);
}
