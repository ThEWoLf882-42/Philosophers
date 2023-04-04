/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:28:05 by agimi             #+#    #+#             */
/*   Updated: 2023/03/28 13:28:05 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atoi(char *str)
{
	size_t	i;
	size_t	y;
	size_t	sign;

	i = 0;
	y = 0;
	sign = 1;
	while (ft_isspace(str[y]))
		y++;
	if (str == 0)
		return (0);
	if (str[y] == '-' || str[y] == '+')
	{
		if (str[y] == '-')
			sign = -1;
		y++;
	}
	while (str[y] && str[y] >= '0' && str[y] <= '9')
	{
		i = i * 10 + str[y] - '0';
		y++;
	}
	return (i * sign);
}
