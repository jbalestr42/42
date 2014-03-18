/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:59:39 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 16:32:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "ft_minishell2.h"
#include <stdlib.h>

t_token			*new_list(char *str)
{
	t_token		*new;

	if (!str)
		return (NULL);
	if (!(new = (t_token *)malloc(sizeof(t_token))))
		return (NULL);
	new->str = str;
	new->type = -1;
	new->next = NULL;
	return (new);
}

void			push_back(t_token **begin, t_token *new)
{
	t_token		*tmp;

	if (!new)
		return ;
	if (*begin == NULL)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void			del_list(t_token **begin)
{
	t_token		*tmp;

	while (*begin)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		ft_strdel(&tmp->str);
		free(tmp);
		tmp = NULL;
	}
}
