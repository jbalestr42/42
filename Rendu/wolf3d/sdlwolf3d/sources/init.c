/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:13:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/02 20:29:40 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>

void		ft_envdel(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	if (!e)
		return ;
	if (e->points)
	{
		while (i < e->nb_line)
		{
			j = 0;
			while (j < e->size[i])
				free(e->points[i][j++]);
			i++;
		}
	}
	if (e->size)
		free(e->size);
	free(e);
}

t_env		*ft_envnew(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->screen = NULL;
	e->points = NULL;
	e->size = NULL;
	e->nb_line = 0;
	return (e);
}
