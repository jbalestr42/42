/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:54:11 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/11 10:33:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int			ft_strlen(char const *s)
{
	int				len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int					is_valid_name(char const *f)
{
	int				l;

	l = ft_strlen(f);
	if (l > 4 && f[l - 1] == 'j' && f[l - 2] == 'b' && f[l - 3] == 'o'
			&& f[l - 4] == '.')
		return (1);
	return (0);
}

void				read_float(char const *s, float *values, int nb_values)
{
	char			**tmp;
	int				i;

	i = 0;
	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) >= nb_values)
	{
		while (i < nb_values)
		{
			values[i] = atof(tmp[i]);
			i++;
		}
	}
	if (tmp)
		free_split(tmp);
}
