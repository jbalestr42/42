/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 02:36:01 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/15 15:47:36 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

/*
** Error cases
*/
# define ERR_MEM		12

# define BUFF_SIZE		409600
# define TAB_SIZE		65535

typedef struct		s_pair
{
	char			*key;
	char			*value;
	struct s_pair	*left;
	struct s_pair	*right;
}					t_pair;

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;


#include "stdint.h"
uint32_t		hash5(const char * data);
int				get_next_line(int const fd, char **line);
int				error(int err);
int				hash(char *str);
void			avl_del(t_pair *tab[TAB_SIZE]);
void			search_entry(t_pair *tab[TAB_SIZE]);
int				add_entry(t_pair *tab[TAB_SIZE], t_pair *leaf, char *line);

/*
** Helpers
*/
void			ft_putendl(char const *s);
void			ft_putstr(char const *s);
char			*ft_strdup(const char *s1);
void			ft_strdel(char **as);
int				ft_strcmp(const char *s1, const char *s2);
unsigned int	ft_strlen(const char *s);
t_pair			*ft_avladd(t_pair *head, char *key, t_pair **leaf);
int				ft_avlheight(t_pair *pair);
void			ft_avldel(t_pair **head);
void			ft_avlsearch(t_pair *tree, char *key, char **ret);
t_pair			*ft_avlnew(char *key);

#endif /* HOTRACE_H */
