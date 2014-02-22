/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:44:12 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:44:38 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "ft_error.h"
#include <libft.h>
#include <stdio.h>
#include <dirent.h>

t_bool	ft_dir_isvalid(t_avl *tmp, char *name)
{
	if (ft_get_file_type(((t_param *)(tmp->content))->st_mode) == 'd')
	{
		if (ft_strcmp("..", name) != 0 && ft_strcmp(".", name))
			return (TRUE);
	}
	return (FALSE);
}

void	ft_add_file(t_data *data, char *path, char *name, t_avl **file)
{
	t_avl	*tmp;

	if ((ft_strchr(data->opts, OPT_A) && *name == '.') || *name != '.')
	{
		tmp = ft_avlnew(ft_param_new(data, path, name), sizeof(t_param));
		if (ft_strchr(data->opts, OPT_T) > 0)
			*file = ft_avladd(*file, tmp, &ft_cmp_date);
		else
			*file = ft_avladd(*file, tmp, &ft_cmp_name);
	}
}

void	ft_add_dir(t_data *data, char *path, char *name, t_avl **dir)
{
	t_avl	*tmp;

	tmp = ft_avlnew(ft_param_new(data, path, name), sizeof(t_param));
	if (ft_strchr(data->opts, OPT_REC))
	{
		if (ft_dir_isvalid(tmp, name))
		{
			if (ft_strchr(data->opts, OPT_T) > 0)
				*dir = ft_avladd(*dir, tmp, &ft_cmp_date);
			else
				*dir = ft_avladd(*dir, tmp, &ft_cmp_name);
		}
	}
}

void	ft_sort_dir(t_data *data, char *param)
{
	t_dirent	*ep;
	DIR			*dp;
	t_avl		*dir;
	t_avl		*file;

	dir = NULL;
	file = NULL;
	if ((dp = opendir(param)))
	{
		while ((ep = readdir(dp)))
		{
			ft_add_file(data, param, ep->d_name, &file);
			ft_add_dir(data, param, ep->d_name, &dir);
		}
		closedir(dp);
	}
	else
		perror(param);
	ft_print(data, file);
	if (file)
		ft_avldel(&file, &ft_param_del);
	if (ft_strchr(data->opts, OPT_REC))
		ft_recursive(data, dir);
	if (dir)
		ft_avldel(&dir, &ft_param_del);
}

void	ft_ls(t_data *data)
{
	int		i;

	i = 0;
	if (data->nb_params == 0)
		ft_sort_dir(data, CURRENT_DIR);
	else
	{
		while (i < data->nb_params)
			ft_sort_dir(data, ft_strjoin(data->params[i++], "/"));
	}
}
