/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 16:11:03 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 17:02:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell2.h"
#include "ft_minishell1.h"

// ajouter token prev pour verifier si un un STR a le meme nom que CMD et pour
// le considerer en tant que STR et non CMD
// ex: ls -al ls -> le deuxieme ls est un fichier qui s'appel ls
// verifier si le prev de STR n'est pas NULL et pas PIPE ou SC
static int		define_type(t_token *tok, t_token *prev, t_lex *lex, char **envp)
{
	int			i;
	char		*path;

	i = -1;
	while (++i < NB_LEX)
	{
		if (!ft_strcmp(lex[i].str, tok->str))
			tok->type = lex[i].type;
	}
	if ((path = find_path(tok->str, envp)))
	{
		ft_strdel(&path);
		if (prev && (prev->type & ATTR || prev->type & STR || prev->type & CMD))
			tok->type = STR;
		else
			tok->type = CMD;
	}
	if (tok->str[0] == '-')
		tok->type = ATTR;
	if (tok->type < 0)
		tok->type = STR;
	return (1);
}

int				define_types(t_token *token, t_lex *lex, char **envp)
{
	t_token		*prev;

	prev = NULL;
	if (!token)
		return (-1);
	if (token->type & STR & ATTR)
		return (error(PARSE_ERR, token->str));
	while (token)
	{
		if (define_type(token, prev, lex, envp) < 0)
			return (error(PARSE_ERR, token->str));
		prev = token;
		token = token->next;
	}
	return (1);
}
