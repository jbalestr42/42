/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_envi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:15:37 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:16:09 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include <sh.h>

char			*ft_find_in_envi(t_list *envi, char *search)
{
	t_elem		*tmp;
	int			i;

	i = 0;
	tmp = envi->begin;
	while (tmp)
	{
		if (ft_strnequ(tmp->data, search, ft_strlen(search)) == 1)
		{
			while (tmp->data[i] != '\0')
			{
				if (tmp->data[i] == '=')
				{
					i++;
					return (&tmp->data[i]);
				}
				i++;
			}
		}
		tmp = tmp->next;
	}
	return ("-1");
}
