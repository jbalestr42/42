/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 11:01:26 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 15:01:19 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sh.h>

static void	tputs_cursor(char c)
{
	tputs(tgetstr("mr", NULL), 1, tputs_char);
	write(1, &c, 1);
	tputs(tgetstr("me", NULL), 1, tputs_char);
}

static void	create_link(t_char *tc1, t_char *tc2)
{
	tc1->next = tc2;
	tc2->prev = tc1;
}

void		add_list_char(t_char **begin, t_char *new, int pos)
{
	t_char	*tmp;
	t_char	*prev;
	int		i;

	if (!*begin)
		*begin = new;
	else
	{
		prev = NULL;
		tmp = *begin;
		i = -1;
		while (++i < pos && tmp)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev)
			create_link(prev, new);
		if (tmp)
			create_link(new, tmp);
		if (pos == 0)
			*begin = new;
	}
}

t_char		*new_char(char c)
{
	t_char	*new;

	if (!(new = (t_char *)malloc(sizeof(t_char))))
		return (NULL);
	new->c = c;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		print_list_char(t_char *begin, int pos)
{
	int		i;

	i = 0;
	ft_prompt();
	while (begin)
	{
		if (i == pos)
			tputs_cursor(begin->c);
		else
			write(1, &begin->c, 1);
		begin = begin->next;
		i++;
	}
	if (i == pos)
		tputs_cursor(' ');
}
