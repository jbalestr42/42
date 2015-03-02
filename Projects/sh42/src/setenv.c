/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:30:39 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 23:01:33 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

int					ft_setenv(char **c, t_list *envi)
{
	t_elem			*elem;

	ft_print_array(c);
	if (c[1] != NULL)
	{
		if (ft_check_fitenvi(c[1]) == 1)
		{
			if (!(elem = ft_list_create_elem(TYPE_DATA)))
				return (-1);
			elem->data = ft_strdup(c[1]);
			if (ft_exist_in_envi(envi, c[1]) == 0)
			{
				if (!ft_list_push_back(envi, elem))
					return (-1);
			}
			else
				ft_replace_line(envi, ft_trim_search(c[1]), ft_strdup(c[1]));
		}
		else
			ft_putstr_fd("Invalid setenv : \"setenv VAR=string\"\n", 2);
	}
	else
		ft_putstr_fd("Argument needed : \"setenv VAR=string\"\n", 2);
	return (1);
}
