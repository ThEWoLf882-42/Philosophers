/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:36:11 by agimi             #+#    #+#             */
/*   Updated: 2023/05/15 16:11:13 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died(t_phi *phi, t_th *th)
{
	pthread_mutex_lock(&phi->mprint);
	printf("%ld %d died\n", now(th->st), th->id);
	pthread_mutex_unlock(&phi->mprint);
}
