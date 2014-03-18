/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 13:44:01 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 17:08:03 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include "ft_minishell1.h"

// supprimer cette fonction
/*static int		nb_type(t_check *check, int type)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (++i < NB_TYPE)
	{
		if (check[i].type & type)
			nb++;
	}
	return (nb);
}*/

static int		check_rule(t_token *token, t_check *check)
{
	int		index;

	if (!token || !(token->next))
		return (1);
	index = log_2(token->type);
	if (check[index].type & token->next->type)
	{
		return (check_rule(token->next, check));
		// verifier si c'est utile de garder le token
		//check[index].current = token;
			if (check_rule(token->next, check))
				return (1);
	}
	return (error(PARSE_ERR, token->next->str));
}

int				log_2(int type)
{
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	while (42)
	{
		if (type / i == 1)
			return (nb);
		nb++;
		i *= 2;
	}
	return (42);
}

// si erreur, il faut free la liste dans cette fonction
int				check_rules(t_token *token, char **envp)
{
	t_check		check[NB_TYPE];
	t_lex		lex[NB_LEX];

	init_check(check);
	init_lexs(lex);
	if (define_types(token, lex, envp) < 0)
		return (0);
	if (check_rule(token, check) > 0)
		return (1);
	return (0);
}
