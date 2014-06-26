/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:16:52 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:16:53 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sh.h>
#include <libft.h>

static int				ft_get_bloc_size(char *line, int i)
{
	int					sep_count;
	int					size;
	int					sep;

	sep_count = 0;
	size = 0;
	sep = 0;
	if (ft_check_sep(line, i) == -1)
		sep_count++;
	while (line[i] && sep_count != 2)
	{
		if ((sep = ft_check_sep(line, i)) != -1)
		{
			size += g_sep_size[sep];
			sep_count++;
			i += g_sep_size[sep];
		}
		else
		{
			size++;
			i++;
		}
	}
	return (size);
}

char					*ft_get_bloc(char *line, int *i)
{
	const int			bloc_size = ft_get_bloc_size(line, *i);
	char				*bloc;
	int					j;
	int					i_copy;

	bloc = NULL;
	if (!(bloc = (char *)malloc(sizeof(char) * bloc_size + 1)))
	{
		perror("ft_add_bloc()");
		return (NULL);
	}
	j = 0;
	i_copy = *i;
	while (*i < i_copy + bloc_size)
	{
		bloc[j] = line[*i];
		j++;
		(*i)++;
	}
	bloc[bloc_size] = '\0';
	if (*i == (int)ft_strlen(line))
		return (bloc);
	while (ft_check_sep(line, *i) == -1)
		(*i)--;
	return (bloc);
}
