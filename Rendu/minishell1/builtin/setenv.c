/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 20:08:37 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 04:24:24 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char		**set(char **envp, char *tmp, char *value, int index)
{
	tmp = ft_strjoin(tmp, value);
	envp[index] = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (envp);
}

char			**ft_setenv(char **envp, char *key, char *value, int override)
{
	int		index;
	char	*envp_key;
	char	*separator;
	char	*tmp;

	if (envp_check(envp) < 0)
		return (NULL);
	index = 0;
	tmp = ft_strjoin(key, "=");
	while (envp[index])
	{
		separator = ft_strchr(envp[index], '=');
		envp_key = ft_strsub(envp[index], 0, separator - envp[index]);
		if (!ft_strcmp(key, envp_key))
		{
			if (override)
				return (set(envp, tmp, value, index));
			else
				return (NULL);
		}
		free(envp_key);
		index++;
	}
	envp[index] = ft_strjoin(tmp, value);
	envp[++index] = NULL;
	return (envp);
}

void			parse_setenv(char **argv, char **envp)
{
	ft_setenv(envp, argv[1], argv[2], ft_atoi(argv[3]));
}
