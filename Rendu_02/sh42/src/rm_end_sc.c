/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_end_sc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 02:16:51 by hjeannin          #+#    #+#             */
/*   Updated: 2014/05/18 22:09:48 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		ft_end(char **a, int start)
{
	while (a[start])
	{
		if (a[start][0] != ';')
			return (1);
		start++;
	}
	return (0);
}

void			ft_rm_end_sc(char **a)
{
	int			i;

	i = 0;
	while (a[i])
	{
		if (ft_end(a, i) == 0)
			a[i] = '\0';
		i++;
	}
}
