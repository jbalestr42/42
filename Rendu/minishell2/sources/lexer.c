/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:34:48 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 16:23:24 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "ft_minishell2.h"
#include <stdlib.h>

static int		ft_isvalid(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (0);
	return (1);
}

static int		ft_isoperator(const char *s)
{
	t_lex		lex[NB_LEX];
	int			i;

	i = 0;
	init_lexs(lex);
	while (i < NB_LEX)
	{
		if (!ft_strncmp(s, lex[i].str, lex[i].len))
			return (lex[i].len);
		i++;
	}
	return (0);
}

t_token			*lexer(char const *s)
{
	int			i;
	int			len;
	int			last;
	t_token		*begin;

	i = 0;
	begin = NULL;
	while (s[i])
	{
		while (s[i] && !ft_isvalid(s[i]))
			i++;
		last = i;
		while (s[i] && ft_isvalid(s[i]))
		{
			if ((len = ft_isoperator(&s[i])) > 0)
			{
				if (i - last > 0)
					push_back(&begin, new_list(ft_strsub(s, last, i - last)));
				push_back(&begin, new_list(ft_strsub(s, i, len)));
				i += len;
				last = i;
			}
			else
				i++;
		}
		if (i - last > 0)
			push_back(&begin, new_list(ft_strsub(s, last, i - last)));
	}
	return (begin);
}
