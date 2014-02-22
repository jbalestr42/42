/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 19:24:25 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/21 20:21:52 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_strcontains(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int				ft_isvalidstr(char c)
{
	if (ft_strcontains("", c) || ft_isdigit(c))
		return (1);
	return (0);
}

int				ft_isvalidnbr(char c)
{
	if (ft_strcontains("-+ ", c) || ft_isdigit(c))
		return (1);
	return (0);
}

int				ft_isvalidfnbr(char c)
{
	if (ft_strcontains("-+ #", c) || ft_isdigit(c))
		return (1);
	return (0);
}

int				ft_isvalidunbr(char c)
{
	if (ft_strcontains("-#", c) || ft_isdigit(c))
		return (1);
	return (0);
}
