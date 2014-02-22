/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 20:07:07 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 04:13:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static void		ft_env(char **envp)
{
	int		index;

	envp_check(envp);
	index = 0;
	while (envp[index])
		ft_putendl(envp[index++]);
}

void			parse_env(char **argv, char **envp)
{
	(void)argv;
	ft_env(envp);
}
