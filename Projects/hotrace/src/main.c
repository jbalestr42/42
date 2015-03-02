/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 21:00:26 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:37:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

int		main(void)
{
	t_pair		*tab[TAB_SIZE];
	t_pair		*leaf;
	char		*line;
	int			i;
	int			err;

	i = 0;
	leaf = NULL;
	line = NULL;
	while (i < TAB_SIZE)
		tab[i++] = NULL;
	if ((err = add_entry(tab, leaf, line)) != 0)
		return (err);
	search_entry(tab);
	avl_del(tab);
	return (0);
}

void	search_entry(t_pair *tab[TAB_SIZE])
{
	char	*line;
	char	*ret;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_avlsearch(tab[hash(line)], line, &ret);
		if (!ret)
		{
			ft_putstr(line);
			ft_putendl(": Not found.");
		}
		else
		{
			ft_putendl(ret);
			ret = NULL;
		}
		ft_strdel(&line);
	}
}

int		add_entry(t_pair *tab[TAB_SIZE], t_pair *leaf, char *line)
{
	int			i;
	int			count;

	i = 0;
	count = 1;
	while (get_next_line(0, &line))
	{
		if (count % 2 == 1)
		{
			if (!*line)
				break ;
			i = hash(line);
			if (!(tab[i] = ft_avladd(tab[i], line, &leaf)))
				return (error(ERR_MEM));
		}
		else
		{
			leaf->value = ft_strdup(line);
			leaf = NULL;
		}
		count++;
		ft_strdel(&line);
	}
	return (0);
}

void	avl_del(t_pair *tab[TAB_SIZE])
{
	int		i;

	i = 0;
	while (i < TAB_SIZE)
		ft_avldel(&tab[i++]);
}

int		hash(char *str)
{
	int		i;
	int		cnt;
	int		len;

	i = 0;
	cnt = 0;
	len = ft_strlen(str);
	while (str[cnt])
	{
		if (str[cnt] % 2)
			i += (str[cnt] << 2) | (str[0] ^ cnt);
		else
			i += (str[cnt] >> 2) | (str[len - 1] & cnt);
		i += (str[cnt] << 2) | (str[len - 1] ^ 2);
		i += (str[cnt] << 2) | (str[len - 1] ^ 2);
		i += (str[cnt] << 2) | (str[len - 1] ^ 2);
		cnt++;
	}
	return (i % TAB_SIZE);
}
