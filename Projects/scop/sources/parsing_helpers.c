/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:54:11 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:35:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
