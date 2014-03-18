/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:22:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/21 14:06:22 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

int			ft_strlen_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int			ft_free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			ft_strdel(&tab[i]);
			i++;
		}
		free(tab);
	}
	return (0);
}

void		del_env(t_env *e)
{
	(void)e;
}

t_env		*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->nb_ant = 0;
	e->ants = NULL;
	e->start = NULL;
	e->end = NULL;
	e->rooms = NULL;
	if (!init_graph(e))
	{
		del_env(e);
		return (NULL); // perror
	}
	return (e);
}
