/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:59:23 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 16:26:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "ft_minishell2.h"

static t_check		init_type(int type)
{
	t_check			check;

	check.type = type;
	check.current = NULL;
	return (check);
}

void				init_check(t_check *check)
{
	check[log_2(CMD)] = init_type(
			ATTR | STR | SC | PIPE | LR | RR | LRR | RRR | END);
	check[log_2(ATTR)] = init_type(
			ATTR | STR | SC | PIPE | LR | RR | LRR | RRR | END);
	check[log_2(STR)] = init_type(
			STR | SC | PIPE | LR | RR | LRR | RRR | END);
	check[log_2(SC)] = init_type(CMD | SC | LR | RR | LRR | RRR | END);
	check[log_2(PIPE)] = init_type(CMD | LR | RR | LRR | RRR);
	check[log_2(LR)] = init_type(STR);
	check[log_2(RR)] = init_type(STR);
	check[log_2(LRR)] = init_type(STR);
	check[log_2(RRR)] = init_type(STR);
	check[log_2(END)] = init_type(NOTHING);
}

static t_lex		init_lex(char *s, int type)
{
	t_lex	lex;

	if (s)
	{
		lex.str = ft_strdup(s);
		lex.len = ft_strlen(s);
	}
	else
	{
		lex.str = NULL;
		lex.len = -1;
	}
	lex.type = type;
	return (lex);
}

void				init_lexs(t_lex *lexs)
{
	lexs[0] = init_lex(";", SC);
	lexs[1] = init_lex("|", PIPE);
	lexs[2] = init_lex(">", RR);
	lexs[3] = init_lex("<", LR);
	lexs[4] = init_lex(">>", RRR);
	lexs[5] = init_lex("<<", LRR);
}
