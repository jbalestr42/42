/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_in_envi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:10:47 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/25 23:13:57 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh.h>

int				ft_exist_in_envi(t_list *envi, char *search)
{
	t_elem		*tmp;
	char		*search_trimed;

	search_trimed = ft_trim_search(search);
	tmp = envi->begin;
	while (tmp)
	{
		if (ft_strnequ(tmp->data, search_trimed, ft_strlen(search_trimed)) == 1)
		{
			free(search_trimed);
			return (1);
		}
		tmp = tmp->next;
	}
	free(search_trimed);
	return (0);
}
