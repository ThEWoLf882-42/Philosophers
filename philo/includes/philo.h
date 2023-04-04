/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:20:25 by agimi             #+#    #+#             */
/*   Updated: 2023/03/27 16:20:25 by agimi            ###   ########.fr       */
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
	int				ec;
	struct philo	*phi;
	struct th		*next;
}	t_th;


typedef struct philo
{
	int				nph;
	int				td;
	int				te;
	int				ts;
	int				npe;
	int				dead;
	int				*id;
	pthread_mutex_t	mdead;
	pthread_mutex_t	*fork;
	t_th			*th;
}	t_phi;

size_t	ft_atoi(char *str);
int		ft_isspace(size_t c);
void	set_arg(t_phi *phi,int ac, char **av);
void	set_forks(t_phi	*phi);
void	create_thread(t_phi *phi);
void	*thread(void *arg);
size_t	time_ms(void);
size_t	my_sleep(int ms);
size_t	now(size_t st);
t_th	*new_th(t_phi *phi, int id);
void	ft_lstadd_back(t_th *th, t_th *new);
t_th	*ft_lstlast(t_th *lst);
void	eat(t_th *th);
void	take_fork(t_th *th);

#endif