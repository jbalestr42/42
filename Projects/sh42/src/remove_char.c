/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 15:01:11 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 15:03:44 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <stdlib.h>

static void		remove(t_char **begin, t_char *tmp)
{
	if (tmp->prev)
	{
		if (tmp->next)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
		}
		else
		{
			tmp->prev->next = NULL;
			free(tmp);
		}
	}
	else if (tmp->next)
	{
		*begin = tmp->next;
		tmp->next->prev = NULL;
		free(tmp);
	}
	else
	{
		free(tmp);
		*begin = NULL;
	}
}

int				remove_char(t_data *data, t_char **begin, int pos)
{
	t_char		*tmp;
	int			i;

	if (*begin == NULL || pos < 0 || data->nb_c == 0)
		return (0);
	tmp = *begin;
	i = 0;
	while (tmp)
	{
		if (i == pos)
		{
			remove(begin, tmp);
			data->nb_c--;
			return (1);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}
