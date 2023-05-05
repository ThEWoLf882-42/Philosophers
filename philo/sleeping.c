/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:28:20 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 12:34:18 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_th *th)
{
	pthread_mutex_lock(&th->phi->mprint);
	printf("%zu %d is sleeping\n", now(th->st), th->id);
	pthread_mutex_unlock(&th->phi->mprint);
}
