/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   died.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:36:11 by agimi             #+#    #+#             */
/*   Updated: 2023/05/16 10:54:07 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	died(t_phi *phi, t_th *th)
{
	pthread_mutex_lock(&phi->mprint);
	printf("%zu %d died\n", now(th->st), th->id);
	pthread_mutex_unlock(&phi->mprint);
}
