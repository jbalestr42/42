/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:45:11 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:45:13 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	ft_print_param(t_avl *node)
{
	ft_putendl(((t_param *)(node->content))->name);
}

void	ft_print_param_l(t_param *param)
{
	char	c;

	ft_putchar(ft_get_file_type(param->st_mode));
	ft_putchar(c = (param->st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar(c = (param->st_mode & S_IWUSR ? 'w' : '-'));
	ft_putchar(c = (param->st_mode & S_IXUSR ? 'x' : '-'));
	ft_putchar(c = (param->st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar(c = (param->st_mode & S_IWGRP ? 'w' : '-'));
	ft_putchar(c = (param->st_mode & S_IXGRP ? 'x' : '-'));
	ft_putchar(c = (param->st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar(c = (param->st_mode & S_IWOTH ? 'w' : '-'));
	ft_putchar(c = (param->st_mode & S_IXOTH ? 'x' : '-'));
	ft_putstr("  ");
}

void	ft_print_space(int len, int len_max)
{
	while (len < len_max)
	{
		ft_putchar(' ');
		len++;
	}
}

int		ft_intlen(int nb)
{
	int		i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	ft_get_file_type(mode_t mode)
{
	char	c;

	c = '-';
	c = S_ISDIR(mode) ? 'd' : c;
	c = S_ISCHR(mode) ? 'c' : c;
	c = S_ISBLK(mode) ? 'b' : c;
	c = S_ISFIFO(mode) ? 'p' : c;
	c = S_ISLNK(mode) ? 'l' : c;
	c = S_ISSOCK(mode) ? 's' : c;
	return (c);
}
