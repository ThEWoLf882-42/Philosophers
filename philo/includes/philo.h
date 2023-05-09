/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:20:25 by agimi             #+#    #+#             */
/*   Updated: 2023/05/09 11:59:16 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct th
{
	size_t			st;
	size_t			le;
	int				id;
	int				i;
	int				ec;
	struct philo	*phi;
	struct th		*next;
}	t_th;

typedef struct philo
{
	int					nph;
	int					td;
	int					te;
	int					ts;
	int					npe;
	int					dead;
	int					done;
	int					*id;
	pthread_mutex_t		fork[200];
	pthread_mutex_t		mec[200];
	pthread_mutex_t		mle[200];
	pthread_mutex_t		mdone;
	pthread_mutex_t		mprint;
	pthread_mutex_t		mdead;
	t_th				*th;
}	t_phi;

int		ft_atoi(char *str);
int		ft_isspace(int c);
int		ft_isnu(char *s);
void	set_arg(t_phi *phi, int ac, char **av);
void	set_forks(t_phi	*phi);
int		create_thread(t_phi *phi);
void	*thread(void *arg);
size_t	time_ms(void);
void	my_sleep(size_t	now, int ms);
size_t	now(size_t st);
t_th	*new_th(t_phi *phi, int id);
void	ft_lstadd_back(t_th *th, t_th *new);
t_th	*ft_lstlast(t_th *lst);
void	eat(t_th *th);
void	take_forks(t_th *th);
int		create_mon(t_phi *phi);
void	*mon(void *arg);
void	sleeping(t_th *th);
void	think(t_th *th);
void	forking(t_th *th, int id);
void	died(t_phi *phi, t_th *th);
int		check_arg(char **av, t_phi *phi);
void	the_free(t_phi *phi);

#endif