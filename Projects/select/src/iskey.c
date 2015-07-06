/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:17 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:04:04 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		treset(t_data *data)
{
	tputs(tgetstr("te", NULL), 1, tputchar);
	tputs(tgetstr("ve", NULL), 1, tputchar);
	flags(&(data->term));
	tcsetattr(0, 0, &(data->term));
}

void		is_space(t_data *data, char *key)
{
	t_word	*tmp;

	if (key[0] == ' ' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		tmp = curword(data);
		if (tmp->sel == 0)
		{
			tmp->und = 0;
			tmp->sel = 1;
			tmp->next->und = 1;
			data->tsel++;
			data->current++;
		}
		else
		{
			data->tsel--;
			tmp->sel = 0;
		}
	}
}

int			is_enter(t_data *data, char *key)
{
	int		i;
	int		j;

	if (key[0] == '\n' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		i = 0;
		j = 0;
		treset(data);
		while (i < data->size)
		{
			if (data->words->sel)
			{
				ft_putstr(data->words->str);
				if (j < data->tsel - 1)
					write(1, " ", 1);
				j++;
			}
			data->words = data->words->next;
			i++;
		}
		if (data->tsel)
			write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int			is_del(t_data *data, char *key)
{
	t_word	*tmp;

	if ((key[0] == 27 && key[1] == '[' && key[2] == '3' && key[3] == '~')
		|| (key[0] == 127 && key[1] == 0 && key[2] == 0 && key [3] == 0))
	{
		if (data->size == 1)
		{
			treset(data);
			return (1);
		}
		tmp = curword(data);
		data->size--;
		if (tmp->sel)
			data->tsel--;
		tmp->next->und = 1;
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		if (!data->current)
			data->words = tmp->next;
		if (data->current > data->size - 1)
			data->current = 0;
		return (0);
	}
	return (0);
}

int			is_esc(t_data *data, char *key)
{
	if (key[0] == 27 && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		treset(data);
		return (1);
	}
	return (0);
}
