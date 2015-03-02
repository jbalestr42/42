/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:44:04 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:50:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <grp.h>
#include <pwd.h>

void		ft_data_del(t_data *data)
{
	int		i;

	i = -1;
	if (data->params != NULL)
	{
		while (++i < data->nb_params)
			free(data->params[i]);
		free(data->params);
	}
	free(data);
	data = NULL;
}

t_data		*ft_data_new(int nb_params)
{
	t_data	*data;

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (!(data->params = (char **)malloc(sizeof(char *) * (nb_params + 1))))
		return (NULL);
	data->params[nb_params] = '\0';
	data->nb_params = nb_params;
	return (data);
}

t_param		*ft_param_new(t_data *data, char *path, char *name)
{
	t_param		*param;
	t_stat		file_stat;
	char		*tmp;
	char		*tmp2;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->name = ft_strdup(name);
	tmp2 = ft_strjoin(path, "/");
	tmp = ft_strjoin(tmp2, name);
	free(tmp2);
	if (stat(tmp, &file_stat) < 0)
		perror(tmp);
	else
		ft_param_new_helper(&param, file_stat, data);
	free(tmp);
	return (param);
}

void		ft_param_new_helper(t_param **param, t_stat file_stat, t_data *data)
{
	(*param)->st_mode = file_stat.st_mode;
	(*param)->tv_sec = file_stat.st_mtimespec.tv_sec;
	(*param)->st_nlink = file_stat.st_nlink;
	if (ft_strchr(data->opts, OPT_L))
	{
		(*param)->user = getpwuid(file_stat.st_uid)->pw_name;
		(*param)->group = getgrgid(file_stat.st_gid)->gr_name;
		(*param)->st_size = file_stat.st_size;
		(*param)->st_blocks = file_stat.st_blocks;
		(*param)->st_rdev = file_stat.st_rdev;
	}
}
