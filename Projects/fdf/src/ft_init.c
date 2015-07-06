/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 15:00:47 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/18 15:35:03 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		ft_envdel(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	if (!e)
		return ;
	if (e->mlx)
		free(e->mlx);
	if (e->win)
		free(e->win);
	if (e->points)
	{
		while (i < e->nb_line)
		{
			j = 0;
			while (j < e->size[i])
				free (e->points[i][j++]);
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
	e->points = NULL;
	e->size = NULL;
	e->nb_line = 0;
	e->cam.x = 0;
	e->cam.y = 0;
	e->cam.z = 0;
	e->scale = 1;
	return (e);
}

t_env		*ft_initpoints(t_env *e, t_line **head)
{
	t_line	*tmp;
	int		elem;

	elem = 0;
	e->points = (t_point ***)malloc(sizeof(t_point **) * e->nb_line);
	if (!e->points)
		return (NULL);
	if (!(e->size = (int *)malloc(sizeof(int) * e->nb_line)))
		return (NULL);
	e->nb_line = 0;
	while (*head)
	{
		e->points[e->nb_line] = ft_intsplit((*head)->str, e->nb_line, &elem);
		e->size[e->nb_line++] = elem;
		tmp = *head;
		*head = (*head)->next;
		if (tmp)
		{
			free(tmp->str);
			free(tmp);
		}
	}
	return (e);
}

t_line		*ft_lstnew(char *line)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->str = line;
	new->next = NULL;
	return (new);
}

t_line		*ft_lstpushback(t_line **head, t_line *new)
{
	t_line	*tmp;

	tmp = *head;
	if (tmp == NULL)
		*head = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (*head);
}
