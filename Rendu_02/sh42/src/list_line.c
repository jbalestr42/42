/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 21:58:52 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/26 14:55:10 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <termcaps.h>
#include <libft.h>

void		add_list_line(t_line **begin, t_line *new)
{
	if (!*begin)
		*begin = new;
	else
	{
		if ((*begin)->prev)
		{
			new->n = (*begin)->prev->n + 1;
			(*begin)->prev->next = new;
			new->prev = (*begin)->prev;
		}
		new->next = (*begin);
		(*begin)->prev = new;
	}
}

t_line		*new_line(t_char *line)
{
	t_line	*new;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	new->n = 0;
	new->line = line;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
