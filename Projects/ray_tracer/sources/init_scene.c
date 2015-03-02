/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:42:52 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 19:01:54 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

static char		*ft_strjoin(char *s1, char *s2)
{
	char		*r;
	int			i;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (*s1)
		r[i++] = *(s1++);
	while (*s2)
		r[i++] = *(s2++);
	r[i] = '\0';
	return (r);
}

int				init_scene(t_env *e, char *path)
{
	char		*name;

	if (e->check_parse == 1)
	{
		del_parse(e);
		e->check_parse = 0;
	}
	e->nb_mesh = 0;
	e->nb_light = 0;
	e->nb_mesh_malloc = -1;
	e->nb_light_malloc = -1;
	name = ft_strjoin("./scenes/", path);
	if (parse(e, name) == -1)
		return (-1);
	e->check_parse = 1;
	free(name);
	return (0);
}
