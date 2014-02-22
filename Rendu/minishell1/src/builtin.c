/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 18:11:41 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 04:37:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

t_builtin			get_builtin(char *name, parser *p)
{
	t_builtin	bu;

	bu.name = name;
	bu.builtin = p;
	return (bu);
}

void				get_builtins(t_builtin *builtins)
{
	builtins[0] = get_builtin("cd", &parse_cd);
	builtins[1] = get_builtin("env", &parse_env);
	builtins[2] = get_builtin("setenv", &parse_setenv);
	builtins[3] = get_builtin("unsetenv", &parse_unsetenv);
	builtins[4] = get_builtin("exit", &parse_exit);
}

void				builtin(char **argv, char **envp, t_builtin *builtins)
{
	int		i;

	i = 0;
	while (i < NB_BUILTIN)
	{
		if (ft_strcmp(builtins[i].name, argv[0]) == 0)
		{
			builtins[i].builtin(argv, envp);
			break ;
		}
		i++;
	}
}
