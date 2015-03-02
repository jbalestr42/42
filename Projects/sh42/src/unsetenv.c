/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 21:41:40 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 23:25:05 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sh.h"

int					ft_unsetenv(char **c, t_list *envi)
{
	char		*search;

	if (c[1] != NULL)
	{
		search = ft_strjoin(c[1], "=");
		ft_remove_line(envi, search);
	}
	else
		ft_putstr("Argument needed : \"ABC\"\n");
	return (1);
}
