/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:54:32 by agimi             #+#    #+#             */
/*   Updated: 2023/05/11 12:17:56 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeping(t_th *th)
{
	pthread_mutex_lock(&th->phi->mprint);
	printf("%zu %d is sleeping\n", now(th->st), th->id);
	pthread_mutex_unlock(&th->phi->mprint);
}
