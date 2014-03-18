/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:58:18 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 11:58:21 by jbalestr         ###   ########.fr       */
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
