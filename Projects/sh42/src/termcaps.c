/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:41:30 by fcorbel           #+#    #+#             */
/*   Updated: 2014/06/26 13:43:23 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <term.h>
#include <sh.h>

int				tputs_char(int c)
{
	write(isatty(1), &c, 1);
	return (1);
}

void			clear_line(t_data *data)
{
	(void)data;
	tputs(tgetstr("cb", NULL), 1, tputs_char);
	tputs(tgetstr("rc", NULL), 1, tputs_char);
}
