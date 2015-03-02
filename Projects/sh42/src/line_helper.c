/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:52:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 15:00:41 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <stdlib.h>

t_char			*copy_line(t_char *c)
{
	t_char		*new;
	int			i;

	i = 0;
	new = NULL;
	while (c)
	{
		add_list_char(&new, new_char(c->c), i);
		c = c->next;
		i++;
	}
	return (new);
}

void			free_line(t_char *c)
{
	t_char		*tmp;

	while (c)
	{
		tmp = c;
		c = c->next;
		free(tmp);
	}
}

int				count_char(t_char *c)
{
	int			i;

	i = 0;
	while (c != NULL)
	{
		c = c->next;
		i++;
	}
	return (i);
}

char			*convert_line(t_data *data)
{
	char		*line;
	int			i;
	t_char		*tmp;

	line = NULL;
	if (!(line = (char *)malloc(sizeof(char) * (data->nb_c + 1))))
		return (NULL);
	i = 0;
	tmp = data->last->line;
	while (tmp)
	{
		line[i] = tmp->c;
		i++;
		tmp = tmp->next;
	}
	line[i] = '\0';
	return (line);
}
