/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:59:15 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 14:28:33 by jbalestr         ###   ########.fr       */
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
