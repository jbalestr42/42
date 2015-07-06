/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 16:23:01 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/09 16:26:08 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sh.h>

char		**ft_str_to_tab(char *line)
{
	char		**tab;

	if (!(tab = ft_strsplit2(line, ' ', '\t')))
		return (NULL);
	return (tab);
}
