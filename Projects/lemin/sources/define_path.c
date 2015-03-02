/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/21 13:51:13 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/21 16:13:52 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

static int		push_path(t_plist **begin, t_path *new)
{
	t_plist		*tmp;

	if (!(tmp = (t_plist *)malloc(sizeof(t_plist))))
		return (0);
	tmp->path = new;
	tmp->next = NULL;
	if (!*begin)
		*begin = tmp;
	else
	{
		tmp->next = *begin;
		*begin = tmp;
	}
	return (1);
}

static void		add_pheromone(t_ant *ant)
{
	t_plist		*tmp;

	tmp = ant->path;
	while (tmp)
	{
		tmp->path->phero = tmp->path->phero * 0.9 + 1;
		tmp = tmp->next;
	}
}

static int		valid_room(t_env *e, t_ant *ant, t_path *tmp, t_path *max)
{
	t_plist		*tmpp;

	(void)ant;
	if (max && tmp->phero > max->phero && tmp->room != e->start && tmp->room->state == EMPTY)
	{
		tmpp = ant->path;
		while (tmpp)
		{
			if (ft_strequ(tmpp->path->room->name, tmp->room->name))
				return (0);
			tmpp = tmpp->next;
		}
		return (1);
	}
	return (0);
}

// on peut eviter les impasses !
static void		next_step(t_env *e)
{
	t_path		*tmp;
	t_path		*max;
	int			i;

	i = -1;
	while (++i < e->nb_ant)
	{
		// si la fourmis est arrivee on passe a la suivante
		if (e->ants[i]->cur == e->end)
			continue ;
		// on recupere la liste des voisins
		tmp = e->ants[i]->cur->neighbour;
		max = NULL;
		// on cherche le meilleur voisin (le plus de pheromone) non occupe
		while (tmp) // tmp = liste de rooms
		{
			if (tmp->room == e->end)
			{
				max = tmp;
				break ;
			}
			else if (!max && tmp->room != e->start &&  tmp->room->state == EMPTY)
				max = tmp;
			else if (valid_room(e, e->ants[i], tmp, max))
				max = tmp;
			tmp = tmp->next;
		}
		if (max) // si il y a un voisin
		{
			e->ants[i]->cur->state = EMPTY; // on vide la piece actuelle
			e->ants[i]->cur = max->room; // on assigne la nouvele piece
			e->ants[i]->cur->state = FULL;      // on rempli la piece
			push_path(&e->ants[i]->path, max); // on rajoute le chemin a la fourmis
			if (e->ants[i]->cur == e->end) // si la piece est la deniere piece
				add_pheromone(e->ants[i]); // on ajoute les pheromone sur le chemin
		}
	}
}

static void		display_ant(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->num);
	ft_putchar('-');
	ft_putstr(ant->cur->name);
	ft_putchar(' ');
}

static void		debug(t_path *rooms)
{
	while (rooms)
	{
		ft_putendl(rooms->room->name);
		while (rooms->room->neighbour)
		{
			ft_putstr("   ");
			ft_putnbr(rooms->room->neighbour->phero);
			ft_putstr(" - ");
			ft_putendl(rooms->room->neighbour->room->name);
			rooms->room->neighbour = rooms->room->neighbour->next;
		}
		rooms = rooms->next;
	}
}

// gerer les graphe sans solutions
void			find_path(t_env *e)
{
	int			i;
	int			finished;

	finished = 0;
	while (!finished)
	{
		next_step(e);
		finished = 1;
		i = -1;
		ft_putendl("");
		while (++i < e->nb_ant)
		{
			if (e->ants[i]->cur != e->start && e->ants[i]->cur != e->end)
				display_ant(e->ants[i]);
			else if (e->ants[i]->cur == e->end && !e->ants[i]->displayed)
			{
				display_ant(e->ants[i]);
				e->ants[i]->displayed = 1;
			}
			if (e->ants[i]->cur != e->end)
				finished = 0;
		}
	}
	ft_putendl("");
	debug(e->rooms);
}
