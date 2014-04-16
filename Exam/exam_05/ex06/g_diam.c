/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 10:05:10 by exam              #+#    #+#             */
/*   Updated: 2014/03/20 13:14:50 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include  <unistd.h>
#include "gdiam.h"

t_node		*new_node(int val)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->val = val;
	node->nb_neigh = 0;
	node->neigh = NULL;
	node->next = NULL;
	return (node);
}

void		add_node(t_node **begin, t_node *new)
{
	if (!*begin)
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
}

t_node		*find_node(t_node *begin, int val)
{
	t_node	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->val == val)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int			ft_atoi(char *s, int start, int i)
{
	int		nb;

	nb = 0;
	while (start < i)
	{
		nb = nb * 10 + s[start] - '0';
		start++;
	}
	return (nb);
}

int			define_nodes(t_node **begin, char *s)
{
	int		i;
	int		start;
	int		val;
	int		nb_node;

	i = 0;
	nb_node = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '-'))
			i++;
		start = i;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
			i++;
		val = ft_atoi(s, start, i);
		if (!find_node(*begin, val))
		{
			nb_node++;
			add_node(begin, new_node(val));
		}
	}
	return (nb_node);
}

int			find_path(t_node *begin, int val1, int val2)
{
	t_node	*tmp;
	int		i;

	tmp = begin;
	while (tmp)
	{
		if (tmp->val == val1)
		{
			i = -1;
			while (++i < tmp->nb_neigh)
			{
				if (tmp->neigh[i] == val2)
					return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

void		add_path(t_node *begin, int val1, int val2)
{
	t_node	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->val == val1)
		{
			tmp->neigh[tmp->nb_neigh] = val2;
			tmp->nb_neigh++;
		}
		else if (tmp->val == val2)
		{
			tmp->neigh[tmp->nb_neigh] = val1;
			tmp->nb_neigh++;
		}
		tmp = tmp->next;
	}
}

void		define_paths(t_node **begin, char *s)
{
	int		i;
	int		start;
	int		val1;
	int		val2;

	i = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '-'))
			i++;
		start = i;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
			i++;
		val1 = ft_atoi(s, start, i);
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '-'))
			i++;
		start = i;
		while (s[i] && s[i] >= '0' && s[i] <= '9')
			i++;
		val2 = ft_atoi(s, start, i);
		if (!find_path(*begin, val1, val2))
			add_path(*begin, val1, val2);
	}
}

void		malloc_neigh(t_node *begin, int nb_node)
{
	t_node	*tmp;
	int		i;

	tmp = begin;
	while (tmp)
	{
		if (!(tmp->neigh = (int *)malloc(sizeof(int) * nb_node)))
			return ;
		i = -1;
		while (++i < nb_node)
			tmp->neigh[i] = -1;
		tmp = tmp->next;
	}
}

void		add_node_path(t_path *path, int val)
{
	path->nodes[path->nb_node] = val;
	path->nb_node++;
	if (path->nb_node > path->max)
		path->max = path->nb_node;
}

void		rem_path(t_path *path)
{
	path->nb_node--;
}

int			contain_path(t_path *path, int val)
{
	int		i;

	i = -1;
	while (++i < path->nb_node)
	{
		if (path->nodes[i] == val)
			return (1);
	}
	return (0);
}

void		find_longest_path(t_node *begin, t_node *node, t_path *path)
{
	int		i;

	i = -1;
	while (++i < node->nb_neigh)
	{
		if (!contain_path(path, node->neigh[i]))
		{
			add_node_path(path, node->neigh[i]);
			find_longest_path(begin, find_node(begin, node->neigh[i]), path);
			rem_path(path);
		}
	}
}

void		ft_putnbr(int n)
{
	char	c;

	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void		free_all(t_node *begin, t_path *path)
{
	t_node	*tmp;

	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp->neigh);
		free(tmp);
	}
	free(path->nodes);
}

void		g_diam(char *s)
{
	t_path	path;
	t_node	*begin;
	t_node	*tmp;
	int		nb_node;

	begin = NULL;
	nb_node = define_nodes(&begin, s);
	malloc_neigh(begin, nb_node);
	define_paths(&begin, s);
	if (!(path.nodes = (int *)malloc(sizeof(int) * nb_node)))
		return ;
	path.nb_node = 0;
	path.max = 0;
	tmp = begin;
	while (tmp)
	{
		add_node_path(&path, tmp->val);
		find_longest_path(begin, tmp, &path);
		tmp = tmp->next;
		rem_path(&path);
	}
	ft_putnbr(path.max);
	free_all(begin, &path);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		g_diam(argv[1]);
	write(1, "\n", 1);
	return (0);
}
