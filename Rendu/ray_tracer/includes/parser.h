/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:22:29 by glasset           #+#    #+#             */
/*   Updated: 2014/03/19 15:20:07 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define START_OBJ '{'
# define END_OBJ '}'
# define BREAK ':'
# define BREAK2 ','
# define COMMENT '#'
# include <string.h>
# include "ray_tracer.h"
# include "gnl.h"

typedef			int(*f)(t_env *, int, int, char *);
int		ft_strcmp(const char *s1, const char *s2);
f			*funct(void);
int			comment(t_env *e, int c_l, int fd, char *str);
int			cut_space(char *str);
int			ft_strlen(char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
void		error_p(char *s1, char *s2, int l);
/*
**	init_info.c
*/
typedef			int(*i)(t_env *e, char *str);
int				ambient(t_env *e, char *str);
int				look(t_env *e, char *str);
int				pov(t_env *e, char *str);
int				nb_mesh(t_env *e, char *str);
int				nb_light(t_env *e, char *str);

int		ft_atoi(const char *str);
double		ft_atod(char *str);


/*
**	init_mesh.c
*/
typedef			int(*m)(t_env *e, char *str, int nb_m, int flag);
m				*ft_inm(void);
int				init_mesh(t_env *e, int c_l, int fd, char *str);


typedef			int(*l)(t_env *e, char *str, int c);

/*
**	ft_imc.c
*/
int				init_flag(t_env *e, int type, int c);
int				color_m(t_env *e, char *str, int c, int flag);
int				m_open(t_env *e, char *str, int c, int flag);
int				m_diffuse(t_env *e, char *str, int c, int flag);
int				m_radius(t_env *e, char *str, int c, int flag);
int				m_specular(t_env *e, char *str, int c, int flag);
int				m_reflection(t_env *e, char *str, int c, int flag);
int				m_refraction(t_env *e, char *str, int c, int flag);
int				m_position(t_env *e, char *str, int c, int flag);
int				comment_m(t_env *e, char *str, int c, int flag);

int				m_normal(t_env *e, char *str, int c, int flag);
int				m_scale(t_env *e, char *str, int c, int flag);
int				m_rotate(t_env *e, char *str, int c, int flag);
int				m_coef(t_env *e, char *str, int c, int flag);

void		parse(t_env *e, char *path);

/*
**	*f
*/
int			information(t_env *e, int c_l, int fd, char *str);
int			light(t_env *e, int c_l, int fd, char *str);
int			comment_b(t_env *e, char *str);
/*
**	tools.c
*/
f				*funct(void);
t_color			get_color(char *str);
int				check_arg(char *str, int flag);

char			**ft_strsplit(char const *s, char c);
#endif /* !PARSER_H */

