/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:48:56 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 12:11:21 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct philo
{
	int		nph;
	int		td;
	int		te;
	int		ts;
	int		npe;
	sem_t	fork;
}	t_phi;


int		check_arg(char **av, t_phi *phi);
void	set_arg(t_phi *phi, int ac, char **av);

#endif