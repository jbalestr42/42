/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 20:15:44 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/25 22:40:55 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <libft.h>
#include <sh.h>

static char				*ft_find_path(DIR *rep, int i, char *str, char **path)
{
	char				*a[2];
	struct dirent		*file;

	while ((file = readdir(rep)))
	{
		if (ft_strequ(file->d_name, str) == 1)
		{
			if (!(a[0] = ft_strjoin(path[i], "/")))
				return (NULL);
			if (!(a[1] = ft_strjoin(a[0], str)))
				return (NULL);
			free(a[0]);
			ft_free_array(path);
			if (closedir(rep) == -1)
				ft_putstr("closedir Error\n");
			return (a[1]);
		}
	}
	if (closedir(rep) == -1)
		ft_putstr("closedir Error\n");
	return (NULL);
}

char					*ft_find_cmd_path(char *str, t_list *envi)
{
	int					i;
	char				**path;
	DIR					*rep;
	char				*res;

	i = 0;
	path = ft_strsplit(ft_find_in_envi(envi, "PATH"), ':');
	while (path[i])
	{
		rep = opendir(path[i]);
		if (rep != NULL)
			if ((res = ft_find_path(rep, i, str, path)) != NULL)
			{
				return (res);
			}
		i++;
	}
	ft_free_array(path);
	return (NULL);
}
