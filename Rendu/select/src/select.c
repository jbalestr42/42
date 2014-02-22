/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 10:00:25 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/12 19:07:32 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	next_word(t_data *data)
{
	if (data->current < data->size - 1)
		data->current++;
	else
		data->current = 0;
}

void	previous_word(t_data *data)
{
	if (data->current > 0)
		data->current--;
	else
		data->current = data->size - 1;
}

int		is_right(t_data *data, char *key)
{
	if (key[0] == 27 && key[1] == '[' && key[2] == 'C' && key[3] == 0)
	{
		data->words[data->current].und = 0;
		next_word(data);
		while (data->words[data->current].str == NULL)
			next_word(data);
		data->words[data->current].und = 1;
		return (1);
	}
	return (0);
}

int		is_left(t_data *data, char *key)
{
	if (key[0] == 27 && key[1] == '[' && key[2] == 'D' && key[3] == 0)
	{
		data->words[data->current].und = 0;
		previous_word(data);
		while (data->words[data->current].str == NULL)
			previous_word(data);
		data->words[data->current].und = 1;
		return (1);
	}
	return (0);
}

int		is_space(t_data *data, char *key)
{
	if (key[0] == ' ' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		while (data->words[data->current].str == NULL)
			next_word(data);
		data->words[data->current].und = 0;
		data->words[data->current].sel = 1;
		next_word(data);
		data->words[data->current].und = 1;
		return (1);
	}
	return (0);
}

int		is_enter(t_data *data, char *key)
{
	int		index;
	int		len;

	if (key[0] == '\n' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		len = index = 0;
		while (index < data->size)
		{
			if (data->words[index].str != NULL && data->words[index].sel)
				len += ft_strlen(data->words[index].str) + 1;
			index++;
		}
		if (len == 0)
			return (1);
		data->ret = ft_strnew(len - 1);
		index = 0;
		while (index < data->size)
		{
			if (data->words[index].str != NULL && data->words[index].sel)
			{
				ft_strcat(data->ret, data->words[index].str);
				ft_strcat(data->ret, " ");
			}
			index++;
		}
		return (1);
	}
	return (0);
}

int		is_del(t_data *data, char *key)
{
	if ((key[0] == 27 && key[1] == '[' && key[2] == '3' && key[3] == '~')
		|| (key[0] == 127 && key[1] == 0 && key[2] == 0 && key [3] == 0))
	{
		if (data->deleted == data->size - 1)
			return (1);
		while (data->words[data->current].str == NULL)
			next_word(data);
		data->words[data->current].str = NULL;
		data->deleted++;
		while (data->words[data->current].str == NULL)
			next_word(data);
		data->words[data->current].und = 1;
	}
	return (0);
}

int		is_esc(char *key)
{
	if (key[0] == 27 && key[1] == 0 && key[2] == 0 && key[3] == 0)
		return (1);
	return (0);
}

void	reinit(void)
{
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
}

void	ft_select(t_data *data)
{
	char	key[4] = {0};

	while (42)
	{
		reinit();
		display(data);
		key[0] = key[1] = key[2] = key[3] = 0;
		read(0, key, 4);
		if (is_esc(key))
			break ;
		if (is_right(data, key))
			continue ;
		if (is_left(data, key))
			continue ;
		if (is_space(data, key))
			continue ;
		if (is_enter(data, key))
			break ;
		if (is_del(data, key))
			break ;
	}
}
