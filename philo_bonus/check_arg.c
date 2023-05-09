/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:53:31 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 11:54:12 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_arg(char **av)
{
	int	i;

	i = 0;
	while (av[++i])
	{
		if (!ft_isnu(av[i]))
		{
			printf("Only Digit Allowed\n");
			return (0);
		}
	}
	if (ft_atoi(av[1]) > 200)
	{
		printf("+200 Philosopher\n");
		return (0);
	}
	if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
	{
		printf("60ms or more\n");
		return (0);
	}
	return (1);
}
