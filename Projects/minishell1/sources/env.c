/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:58:03 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 11:58:04 by jbalestr         ###   ########.fr       */
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
