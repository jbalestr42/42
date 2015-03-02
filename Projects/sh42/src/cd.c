/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 01:58:39 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 21:06:56 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <libft.h>
#include <sh.h>

static int				ft_normal_chdir(char *cdirpath, char **c)
{
	char				*tmp1;
	char				*tmp2;

	tmp1 = ft_strjoin(cdirpath, "/");
	tmp2 = ft_strjoin(tmp1, c[1]);
	if (chdir(tmp2) == 0)
	{
		free(tmp1);
		free(tmp2);
		return (0);
	}
	free(tmp1);
	free(tmp2);
	return (-1);
}

static int				ft_slc_func(char fc, t_list *envi, char **c, char *cp)
{
	if (fc == '-')
	{
		if (chdir(ft_find_in_envi(envi, "OLDPWD")) == 0)
			return (0);
	}
	if (fc == '/')
	{
		if (chdir(c[1]) == 0)
			return (0);
	}
	if (fc == '~')
	{
		if (chdir(ft_find_in_envi(envi, "HOME")) == 0)
			return (0);
	}
	if (ft_isalnum(fc) || fc == '.')
	{
		if (ft_normal_chdir(cp, c) == 0)
			return (0);
	}
	return (-1);
}

static int				ft_end_pwd(t_list *envi, char *tmp4, char *tmp3)
{
	t_elem				*elem;

	if (ft_replace_line(envi, "PWD", tmp4) == 0)
	{
		if (!(elem = ft_list_create_elem(TYPE_DATA)))
			return (0);
		free(elem->data);
		elem->data = tmp4;
		if (!ft_list_push_back(envi, elem))
			return (0);
	}
	if (ft_replace_line(envi, "OLDPWD", tmp3) == 0)
	{
		if (!(elem = ft_list_create_elem(TYPE_DATA)))
			return (0);
		free(elem->data);
		elem->data = tmp3;
		if (!ft_list_push_back(envi, elem))
			return (0);
	}
	return (1);
}

static void				put_error_msg(char **c)
{
	ft_putstr("cd: no such file or directory :");
	if (c[1] != NULL)
		ft_putendl(c[1]);
	else
		ft_putendl("Tu as pas de $HOME clochard.");
}

int						ft_cd(char **c, t_list *envi)
{
	char				buf[1024];
	char				*cdirpath;
	char				first_char;
	char				*tmp3;
	char				*tmp4;

	if (c[1] != NULL)
		first_char = c[1][0];
	else
		first_char = '~';
	cdirpath = getcwd(buf, 1024);
	tmp3 = ft_strjoin("OLDPWD=", cdirpath);
	if (ft_slc_func(first_char, envi, c, cdirpath) == -1)
	{
		put_error_msg(c);
		free(tmp3);
		return (-1);
	}
	cdirpath = getcwd(buf, 1024);
	tmp4 = ft_strjoin("PWD=", cdirpath);
	if (!ft_end_pwd(envi, tmp4, tmp3))
		return (0);
	return (1);
}
