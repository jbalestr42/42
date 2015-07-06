/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 10:00:44 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 17:58:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int			comment_b(t_env *e, char *str)
{
	(void)e;
	(void)str;
	return (1);
}

int			checkline_inf(char *str)
{
	char	**tmp;
	char	*line;

	tmp = NULL;
	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	line = tmp[0];
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	free(line);
	if (!ft_strcmp(tmp[0], "numbers of light"))
		return (free_ret(1, tmp));
	if (!ft_strcmp(tmp[0], "numbers of object"))
		return (free_ret(2, tmp));
	if (!ft_strcmp(tmp[0], "point of view"))
		return (free_ret(3, tmp));
	if (!ft_strcmp(tmp[0], "look at"))
		return (free_ret(4, tmp));
	if (!ft_strcmp(tmp[0], "color ambient"))
		return (free_ret(5, tmp));
	return (free_ret(-1, tmp));
}
