/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:22:29 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 19:50:51 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <string.h>
# include "ray_tracer.h"
# include "gnl.h"
# define START_OBJ	'{'
# define END_OBJ	'}'
# define BREAK		':'
# define BREAK2		','
# define COMMENT	'#'
# define COLOR_PERL	"0x555555"

typedef struct	s_imesh
{
	int			l;
	int			flag;
	char		*line;
	int			tmp;
	int			count;
	int			cbis;
	int			ret_m;
}				t_imesh;

typedef int		(*t_f)(t_env *e, int c_l, int fd, char *str);
typedef int		(*t_i)(t_env *e, char *str);
typedef int		(*t_l)(t_env *e, char *str, int c);
typedef int		(*t_m)(t_env *e, char *str, int nb_m, int flag);

t_f				*funct(void);
t_i				*ft_inf(void);
t_l				*ft_inl(void);
t_m				*ft_inm(void);

/*
**	parser.c
*/
int				parse(t_env *e, char *path);
int				comment(t_env *e, int c_l, int fd, char *str);

/*
**	init_info.c ft_info_1.c
*/
int				information(t_env *e, int c_l, int fd, char *str);
int				checkline_inf(char *str);
int				comment_b(t_env *e, char *str);
int				ambient(t_env *e, char *str);
int				look(t_env *e, char *str);
int				pov(t_env *e, char *str);
int				nb_mesh(t_env *e, char *str);
int				nb_light(t_env *e, char *str);

/*
**	ft_light_1.c init_light.c
*/
int				light(t_env *e, int c_l, int fd, char *str);
int				comment_l(t_env *e, char *str, int c);
int				color_l(t_env *e, char *str, int c);
int				pos_l(t_env *e, char *str, int c);
int				checkline_light(char *str);

/*
**	init_mesh.c ft_meshe_*.c
*/
int				init_mesh(t_env *e, int c_l, int fd, char *str);
int				call_ft(t_env *e, t_imesh *j, int c, int c_l);
int				check_end_mesh(t_env *e, t_imesh *j, char *str, int c_l);
int				checkline_mesh(char *str);
int				min_arg(int flag);
int				check_mesh_nb(char *str, int fd, int c_l);
int				check_tmp(char *line, int c_l, int l, int tmp);
void			init_base(t_env *e, int flag, int c);
int				m_mat(t_env *e, char *str, int c, int flag);
int				m_perlin(t_env *e, char *str, int c, int flag);
int				m_v(t_env *e, char *str, int c, int flag);
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
int				m_vertex(t_env *e, int c, int i, double *dot);

/*
**	tools.c
*/
int				cut_space(char *str);
int				ft_strlen(char *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
void			error_p(char *s1, char *s2, int l);
int				check_arg(char *str, int flag);
t_color			get_color(char *str);
int				check_col(char *str);
int				ft_atoi(const char *str);
double			ft_atod(char *str);
char			**ft_strsplit(char const *s, char c);
int				free_ret(int ret, char **tmp);
int				free_l(int ret, char *tmp);

#endif
