/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_file.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:58:30 by fcorbel           #+#    #+#             */
/*   Updated: 2014/03/27 11:58:33 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_FILE_H
# define OBJ_FILE_H

# include "objects.h"

typedef struct s_vertices	t_vertices;
typedef struct s_vertices	t_normals;

struct						s_vertices
{
	t_vertex				vec;
	struct s_vertices		*next;
};

typedef struct				s_obj
{
	t_triangle				triangle;
	struct s_obj			*next;
}							t_obj;

/*
** Init obj
*/
t_vertices					*new_vertex(t_vector v);
void						push_vertex(t_vertices **begin, t_vertices *new);
t_obj						*new_triangle(t_triangle t);
void						push_triangle(t_obj **begin, t_obj *new);
double						ft_atod(char *s);
int							ft_strlen_tab(char **tab);
void						free_split(char **s);

#endif
