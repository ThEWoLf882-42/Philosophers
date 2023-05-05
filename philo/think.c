/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:54:42 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 15:54:43 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_th *th)
{
	pthread_mutex_lock(&th->phi->mprint);
	printf("%zu %d is thinking\n", now(th->st), th->id);
	pthread_mutex_unlock(&th->phi->mprint);
}
