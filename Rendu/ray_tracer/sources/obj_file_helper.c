/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_file_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:16:16 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 11:40:48 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "obj_file.h"

int					ft_strlen_tab(char **tab)
{
	int				len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void				free_split(char **s)
{
	int				i;

	i = -1;
	while (s[++i])
		free(s[i]);
}
