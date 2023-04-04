/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:03 by agimi             #+#    #+#             */
/*   Updated: 2023/03/31 15:43:03 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_ms(void)
{
	struct timeval	now;
	int				time;

	gettimeofday(&now, NULL);
	time = 1000 * now.tv_sec + now.tv_usec / 1000;
	return (time);
}

int	now(int st)
{
	return (time_ms() - st);
}