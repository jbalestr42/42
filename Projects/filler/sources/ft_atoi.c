/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 14:49:48 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/22 16:21:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int		total;
	int		is_neg;

	total = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if ((is_neg = *str == '-' ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		total = (total * 10) + (*str++ - '0');
	return (total * is_neg);
}
