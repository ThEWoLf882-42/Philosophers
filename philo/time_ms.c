/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:43:03 by agimi             #+#    #+#             */
/*   Updated: 2023/05/12 11:40:18 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	time_ms(void)
{
	struct timeval	now;
	size_t			time;

	gettimeofday(&now, NULL);
	time = 1000 * now.tv_sec + now.tv_usec / 1000;
	return (time);
}

size_t	now(size_t st)
{
	return (time_ms() - st);
}
