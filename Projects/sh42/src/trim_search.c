/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 18:53:21 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/25 23:10:53 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>

char				*ft_trim_search(char *search)
{
	int				i;
	char			*st;

	i = 0;
	st = NULL;
	while (search[i] != '\0')
	{
		if (search[i] == '=')
		{
			if (!(st = ft_strsub(search, 0, i + 1)))
			{
				perror("\033[31;1mft_trim_search()\033[0m");
				return (NULL);
			}
		}
		i++;
	}
	return (st);
}
