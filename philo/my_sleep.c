/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:33:32 by agimi             #+#    #+#             */
/*   Updated: 2023/04/03 15:33:32 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	my_sleep(int ms)
{
	size_t	now;
	size_t	aft;

	now = time_ms();
	aft = time_ms();
	while ((int)(aft - now) != ms - 2)	
	{
		usleep(1);
		aft = time_ms();
	}
	return (aft - now);
}