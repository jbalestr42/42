/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/06 14:41:15 by exam              #+#    #+#             */
/*   Updated: 2014/03/06 17:11:20 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_DIAM_H
# define G_DIAM_H

typedef struct		s_node
{
	int				val;
	int				*neigh;
	int				visited;
	int				nb_neigh;
}					t_node;

typedef struct		s_list
{
	t_node			*node;
	struct s_list	*next;
}					t_list;

typedef struct		s_path
{
	int				*nodes;
	int				nb_visited;
	int				max;
}					t_path;

t_node		*new_node(int val);
t_list		*new_list(t_node *node);
void		add_node(t_list **begin, t_node *new);
t_list		*find_node(t_list *begin, int val);
int			ft_atoi(char *s, int len);
int			define_nodes(t_list **begin, char *s);
void		add_path(t_list *begin, int fir, int sec);
void		define_neigh(t_list *begin, char *s);
void		malloc_paths(t_list *begin, int nb_node);
void		find_path(t_list *list, t_list *cur, t_path *path);

#endif /* G_DIAM_H */
