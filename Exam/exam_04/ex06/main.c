/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 14:38:22 by exam              #+#    #+#             */
/*   Updated: 2014/03/06 17:07:23 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "g_diam.h"

t_node		*new_node(int val)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->val = val;
	node->visited = 0;
	node->nb_neigh = 0;
	return (node);
}

t_list		*new_list(t_node *node)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->node = node;
	list->next = NULL;
	return (list);
}

void		add_node(t_list **begin, t_node *new)
{
	t_list	*tmp;

	if (*begin == NULL)
		*begin = new_list(new);
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_list(new);
	}
}

t_list		*find_node(t_list *begin, int val)
{
	t_list	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->node->val == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			ft_atoi(char *s, int len)
{
	int		total;
	int		i;

	total = 0;
	i = -1;
	while (s[++i] && i < len)
		total = total * 10 + s[i] - '0';
	return (total);
}

int			define_nodes(t_list **begin, char *s)
{
	int		start;
	int		nb;
	int		i;
	int		nb_node;

	i = 0;
	nb_node = 0;
	while (s[i])
	{
		start = i;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		nb = ft_atoi(&s[start], i - start);
		if (!find_node(*begin, nb))
		{
			nb_node++;
			add_node(begin, new_node(nb));
		}
		if (!s[i])
			break ;
		i++;
	}
	return (nb_node);
}

void		add_path(t_list *begin, int fir, int sec)
{
	t_list	*tmp;
	int		i;

	if (!(tmp = find_node(begin, fir)))
		return ;
	i = -1;
	while (++i < tmp->node->nb_neigh)
	{
		if (tmp->node->neigh[i] == sec)
			return ;
	}
	tmp->node->neigh[tmp->node->nb_neigh] = sec;
	tmp->node->nb_neigh++;
	if (!(tmp = find_node(begin, sec)))
		return ;
	tmp->node->neigh[tmp->node->nb_neigh] = fir;
	tmp->node->nb_neigh++;
}

void		define_neigh(t_list *begin, char *s)
{
	int		start;
	int		i;
	int		fir;
	int		sec;

	i = 0;
	while (s[i])
	{
		start = i;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		fir = ft_atoi(&s[start], i - start);
		i++;
		start = i;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		sec = ft_atoi(&s[start], i - start);
		add_path(begin, fir, sec);
		if (!s[i])
			break ;
		i++;
	}
}

void		malloc_paths(t_list *begin, int nb_node)
{
	t_list	*tmp;
	int		i;

	tmp = begin;
	while (tmp)
	{
		tmp->node->neigh = (int *)malloc(sizeof(int) * nb_node - 1);
		i = -1;
		while (++i < nb_node)
			tmp->node->neigh[i] = -1;
		tmp = tmp->next;
	}
}

int			visited(t_path *path, int val)
{
	int		i;

	i = -1;
	while (++i < path->nb_visited)
	{
		if (path->nodes[i] == val)
			return (1);
	}
	return (0);
}

void		find_path(t_list *begin, t_list *cur, t_path *path)
{
	int		i;

	path->nodes[path->nb_visited] = cur->node->val;
	path->nb_visited++;
	if (path->nb_visited > path->max)
		path->max = path->nb_visited;
	i = -1;
	while (++i < cur->node->nb_neigh)
	{
		if (!visited(path, cur->node->neigh[i]))
			find_path(begin, find_node(begin, cur->node->neigh[i]), path);
	}
	cur = cur->next;
	path->nb_visited--;
}

void		ft_putnbr(int n)
{
	char	c;

	if (n / 10  > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void		free_all(t_list *begin, t_path *path)
{
	t_list	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp->node->neigh);
		free(tmp->node);
		free(tmp);
	}
	if (path)
	{
		free(path->nodes);
		free(path);
	}
}

void		g_diam(char *s)
{
	t_path	*path;
	t_list	*list;
	t_list	*tmp;
	int		nb_node;

	list = NULL;
	nb_node = define_nodes(&list, s);
	malloc_paths(list, nb_node);
	define_neigh(list, s);
	path = (t_path *)malloc(sizeof(t_path));
	path->nodes = (int *)malloc(sizeof(int) * nb_node);
	path->nb_visited = 0;
	path->max = 0;
	tmp = list;
	while (tmp)
	{
		find_path(list, tmp, path);
		tmp = tmp->next;
	}
	ft_putnbr(path->max);
	free_all(list, path);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		g_diam(argv[1]);
	write(1, "\n", 1);
	return (0);
}
