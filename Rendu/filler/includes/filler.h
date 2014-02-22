/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:55:23 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/22 16:41:05 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define P1_CHAR	'O'
# define P2_CHAR	'X'
# define STD_IN		0

/*
** ERR_FL : First line
** ERR_SM : Size map
** ERR_MAL : Malloc fail
*/
# define FAIL		0
# define SUCCESS	1
# define ERR_FL		-1
# define ERR_SM		-2
# define ERR_MAL	-3

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_surface
{
	char			**tab;
	int				height;
	int				width;
}					t_surface;

typedef struct		s_data
{
	char			p_char;
	t_surface		map;
	t_surface		piece;
}					t_data;

/*
** Helpers
*/
char			**ft_strsplit(char const *s, char c);
int				ft_atoi(const char *str);
char			*ft_strdup(char const *s);
unsigned int	ft_strlen(char const *s);
void			ft_strdel(char **s);
void			free_tab(char **tab);
int				ft_read(void);

/*
** Main functions
*/
void			filler(t_data *d);

#endif /* !FILLER_H */
