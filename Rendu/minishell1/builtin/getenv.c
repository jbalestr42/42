/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 20:09:40 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 04:15:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

char	*ft_getenv(char **envp, char *key)
{
	int		index;
	int		i;

	envp_check(envp);
	index = 0;
	while (envp[index])
	{
		i = 0;
		while (envp[i] && key[i] && key[i] == envp[index][i])
			i++;
		if (envp[index][i] == '=')
			return (&envp[index][i + 1]);
		index++;
	}
	return (NULL);
}
