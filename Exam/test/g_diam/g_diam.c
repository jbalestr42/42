#include <unistd.h>
#include <stdlib.h>
#include "g_diam.h"

#include <stdio.h>

int			ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int			get_val(char *s, int start, int end)
{
	int		val;

	val = 0;
	while (start < end)
	{
		val = val * 10 + s[start] - '0';
		start++;
	}
	return (val);
}

void		add_node(t_node **begin, int val, int *nb_node)
{
	t_node	*node;

	node = *begin;
	while (node)
	{
		if (node->val == val)
			return ;
		node = node->next;
	}
	node = (t_node *)malloc(sizeof(t_node));
	node->val = val;
	node->visited = 0;
	node->next = NULL;
	if (!*begin)
		*begin = node;
	else
	{
		node->next = *begin;
		*begin = node;
	}
	*nb_node = *nb_node + 1;
}

t_node		*get_node(t_node *begin, int val)
{
	t_node	*node;

	node = *begin;
	while (node)
	{
		if (node->val == val)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void		g_diam(char *s)
{
	int		**link;
	t_node	*begin;
	int		nb_node;
	int		start;
	int		i;
	t_node	*val1;
	t_node	*val2;

	i = 0;
	nb_node = 0;
	begin = NULL;
	while (s[i])
	{
		start = i;
		while (ft_isdigit(s[i]))
			i++;
		add_node(&begin, get_val(s, start, i), &nb_node);
		if (s[i] != ' ' && s[i] != '-' && !ft_isdigit(s[i]))
			break ;
		i++;
	}
	link = (int **)malloc(sizeof(int *) * nb_node);
	i = -1;
	while (++i < nb_node)
		link[i] = (int *)malloc(sizeof(int) * nb_node);
	i = 0;
	while (s[i])
	{
		start = i;
		while (ft_isdigit(s[i]))
			i++;
		val1 = get_node(begin, get_val(s, start, i));
		i++;
		while (ft_isdigit(s[i]))
			i++;
		val2 = get_node(begin, get_val(s, start, i));
		i++;
		val1->nb_links++;
		link[val1->val]
	}

}

int			main(int argc, char ** argv)
{
	if (argc == 2)
		g_diam(argv[1]);
	write(1, "\n", 1);
	return (0);
}
