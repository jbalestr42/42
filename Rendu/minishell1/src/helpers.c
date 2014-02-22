/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 17:27:29 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 03:18:50 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		envp_check(char **envp)
{
	if (envp == NULL)
		return (error(NOENV, NULL));
	if (*envp == NULL)
		return (error(NOENV, NULL));
	return (1);
}

void	free_split(char **array)
{
	int		index;

	index = 0;
	while (array[index])
		ft_strdel(&array[index++]);
	free(array);
}

int		count_split(char **array)
{
	int		count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}
