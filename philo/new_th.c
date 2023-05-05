/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_th.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:23:10 by agimi             #+#    #+#             */
/*   Updated: 2023/05/05 11:36:49 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_th	*ft_lstlast(t_th *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_th *th, t_th *new)
{
	if (!th || !new)
		return ;
	if (th)
		ft_lstlast(th)->next = new;
	else
		th = new;
}

t_th	*new_th(t_phi *phi, int id)
{
	t_th	*th;

	th = malloc(sizeof(t_th));
	if (!th)
		return (NULL);
	th->id = id;
	th->phi = phi;
	th->ec = 0;
	th->next = NULL;
	if (id == 1)
		phi->th = th;
	else
		ft_lstadd_back(phi->th, th);
	return (th);
}
