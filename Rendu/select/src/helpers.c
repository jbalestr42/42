/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:11:26 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/08 07:57:59 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		error(int quit, char *msg, t_data *data)
{
	ft_putstr(msg);
	if (data)
		reset(data);
	if (quit)
		exit(-1);
	return (-1);
}
