/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:29:27 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 05:10:42 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		ft_atoi(const char *str)
{
	int	res;
	int	i;

	i = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == 43)
		str++;
	else if (*str == '-')
	{
		i = i * (-1);
		str++;
	}
	while ((*str >= '0' && *str <= '9') && *str)
	{
		res = res * 10;
		res = res + *str - '0';
		str++;
	}
	return (res * i);
}
