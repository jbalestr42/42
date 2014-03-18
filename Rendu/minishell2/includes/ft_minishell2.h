/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell2.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:00:58 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 17:03:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL2_H
# define FT_MINISHELL2_H

# define NB_LEX		6
# define NB_TYPE	9
# define NOTHING	0
# define CMD		1
# define ATTR		2
# define STR		4
# define SC			8
# define PIPE		16
# define LR			32
# define RR			64
# define LRR		128
# define RRR		256
# define END		512
 
typedef struct		s_lex
{
	char			*str;
	int				len;
	int				type;
}					t_lex;

typedef struct		s_token
{
	char			*str;
	int				type;
	struct s_token	*next;
}					t_token;

typedef struct		s_check
{
	int				type;
	t_token			*current;
}					t_check;

/*
** Lexer
*/
void		init_lexs(t_lex *lexs);
void		init_check(t_check *check);
t_token		*lexer(char const *s);

/*
** Parser
*/
int			define_types(t_token *token, t_lex *lex, char **envp);
int			check_rules(t_token *token, char **envp);
int			log_2(int nb);

/*
** List
*/
t_token		*new_list(char *s);
void		push_back(t_token **begin, t_token *new);

#endif /* !FT_MINISHELL2_H */
