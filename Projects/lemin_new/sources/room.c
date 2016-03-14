/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 20:38:23 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/14 10:02:19 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		*ft_strdup(char const *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (s2 - len);
}

int			add_new_room(t_room **rooms, char *name)
{
	t_room	*room;

	room = (t_room*)malloc(sizeof(t_room));
	if (!room)
		return (0);
	room->name = name;
	room->next = NULL;
	if (*rooms == NULL)
	{
		*rooms = room;
		(*rooms)->num = 0;
	}
	else
	{
		room->next = *rooms;
		*rooms = room;
		room->num = room->next->num + 1;
	}
	return (1);
}

int			find_room(t_room *rooms, char *name)
{
	t_room	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int			parse_room(t_room **rooms, char **tmp)
{
	int		i;

	i = 0;
	while (i < ft_strlen(tmp[0]))
	{
		if (tmp[0][i] == '-')
			return (return_print(0, "The room name must not contains \'-\'"));
		i++;
	}
	if (find_room(*rooms, tmp[0]))
		return (return_print(0, "The room already exist"));
	if (!is_number(tmp[1]) || !is_number(tmp[2]))
		return (return_print(0, "Coordinates are not numbers"));
	add_new_room(rooms, ft_strdup(tmp[0]));
	return (1);
}

int			create_rooms(t_graph *graph, t_room *rooms)
{
	t_room	*tmp;
	int		i;

	graph->V = rooms->num + 1;
	graph->array = (t_adj_list*)malloc(graph->V * sizeof(t_adj_list));
	graph->room_name = (char**)malloc(sizeof(char*) * rooms->num + 2);
	if (!graph->room_name)
		return (0);
	i = 0;
	while (i < graph->V)
	{
		graph->array[i].head = NULL;
		i++;
	}
	graph->room_count = rooms->num + 1;
	while (rooms)
	{
		tmp = rooms;
		graph->room_name[rooms->num] = rooms->name;
		rooms = rooms->next;
		free(tmp);
	}
	return (1);
}
