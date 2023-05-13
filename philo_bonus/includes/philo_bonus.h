/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:48:56 by agimi             #+#    #+#             */
/*   Updated: 2023/05/13 15:26:16 by agimi            ###   ########.fr       */
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

typedef struct philo_bonus
{
	pthread_t	checker;
	size_t		le;
	int			ec;
	int			id;
}	t_th;

typedef struct philo
{
	pthread_t	checker;
	size_t		st;
	int			nph;
	int			td;
	int			te;
	int			ts;
	int			npe;
	pid_t		*pid;
	sem_t		*fork;
	sem_t		print;
	sem_t		end;
	sem_t		sec;
	t_th		th;
}	t_phi;

int		check_arg(char **av, t_phi *phi);
void	set_arg(t_phi *phi, int ac, char **av);
int		set_forks(t_phi	*phi);
int		forking(t_phi	*phi);
int		ft_atoi(char *str);
int		ft_isspace(int c);
int		ft_isnu(char *s);
void	my_sleep(size_t	now, int ms);
size_t	time_ms(void);
size_t	now(size_t st);
void	tfork(t_phi	*phi);
void	eat(t_phi *phi);
void	thread(t_phi *phi);
void	murder(t_phi *phi, int i);
void	sleeping(t_phi *phi);
void	thinking(t_phi *phi);
int		eat_checker(t_phi *phi);
void	death_checker(t_phi *phi);

#endif