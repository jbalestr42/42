/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 16:04:46 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 03:41:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static t_error	get_error(int exit, char *err_str)
{
	t_error		err;

	err.exit = exit;
	err.err_str = err_str;
	return (err);
}

static void		get_errors(t_error err[NB_ERR])
{
	err[BADCMD] = get_error(0, "sh1: command not found: ");
	err[NSFOD] = get_error(0, "sh1: cd: no such file or directory: ");
	err[INVPTH] = get_error(0, "sh1: cd: invalid path.\n");
	err[NOENV] = get_error(1, "sh1: env: environment is empty.\n");
	err[BADVAL] = get_error(0, NULL);
	err[FORK_FAIL] = get_error(1, "sh1: fork fail.\n");
	err[EXIT] = get_error(1, NULL);
}

int				error(int err_num, char *arg)
{
	t_error		err[NB_ERR];

	get_errors(err);
	if (err_num == BADVAL)
		ft_putendl(arg);
	else
	{
		if (err[err_num].err_str)
			ft_putstr(err[err_num].err_str);
		if (arg)
			ft_putendl(arg);
		if (err[err_num].exit)
			exit(1);
	}
	return (-1);
}
