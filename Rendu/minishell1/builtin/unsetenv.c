/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 19:50:17 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 04:17:47 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int		unset(int index, char **envp, char *envp_key)
{
	ft_strdel(&envp[index]);
	while (envp[index + 1])
	{
		envp[index] = envp[index + 1];
		index++;
	}
	ft_strdel(&envp_key);
	envp[index] = NULL;
	return (1);
}

static int		ft_unsetenv(char **envp, char *key)
{
	int		index;
	char	*envp_key;
	char	*separator;

	if (envp_check(envp) < 0)
		return (-1);
	index = 0;
	while (envp[index])
	{
		separator = ft_strchr(envp[index], '=');
		envp_key = ft_strsub(envp[index], 0, separator - envp[index]);
		if (!ft_strcmp(key, envp_key))
			return (unset(index, envp, envp_key));
		free(envp_key);
		index++;
	}
	return (0);
}

void			parse_unsetenv(char **argv, char **envp)
{
	ft_unsetenv(envp, argv[1]);
}
