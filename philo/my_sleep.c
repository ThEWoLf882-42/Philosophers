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

void	my_sleep(size_t	now, int ms)
{
	size_t	aft;
	
	aft = time_ms();
	while ((aft - now) < (size_t)ms)
	{
		usleep(ms);
		aft = time_ms();
	}
}