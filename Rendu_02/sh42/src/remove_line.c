/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:26:34 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/25 23:32:12 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh.h>

void			ft_remove_line(t_list *envi, char *search)
{
	t_elem		*tmp;

	tmp = envi->begin;
	while (tmp)
	{
		if (ft_strnequ(tmp->data, search, ft_strlen(search)) == 1)
		{
			envi = ft_list_del_elem(envi, tmp);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		ft_putstr("Not found\n");
	free(search);
}
