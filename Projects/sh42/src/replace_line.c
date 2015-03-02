/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:27:01 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/25 21:08:26 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh.h>

int				ft_replace_line(t_list *envi, char *search, char *line)
{
	t_elem		*tmp;

	tmp = envi->begin;
	while (tmp)
	{
		if (ft_strnequ(tmp->data, search, ft_strlen(search)) == 1)
		{
			if (tmp->data)
				free(tmp->data);
			tmp->data = line;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
