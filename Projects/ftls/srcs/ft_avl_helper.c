/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:43:35 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:43:38 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

int		ft_cmp_name(void *c1, void *c2)
{
	t_param		*a1;
	t_param		*a2;

	a1 = (t_param *)c1;
	a2 = (t_param *)c2;
	return (ft_strcmp(a1->name, a2->name));
}

int		ft_cmp_date(void *c1, void *c2)
{
	t_param		*a1;
	t_param		*a2;

	a1 = (t_param *)c1;
	a2 = (t_param *)c2;
	if (a2->tv_sec - a1->tv_sec == 0)
		return (ft_strcmp(a1->name, a2->name));
	return (a2->tv_sec - a1->tv_sec);
}

void	ft_param_del(void *content, size_t content_size)
{
	t_param		*tmp;

	tmp = (t_param *)content;
	if (tmp)
	{
		ft_strdel(&tmp->name);
		ft_memdel(&content);
	}
	(void)content_size;
}

void	ft_recursive(t_data *data, t_avl *head)
{
	t_param		*tmp;

	if (!head)
		return ;
	tmp = (t_param *)head->content;
	if (ft_strchr(data->opts, OPT_REV))
		ft_recursive(data, head->right);
	else
		ft_recursive(data, head->left);
	ft_putchar('\n');
	ft_putstr(tmp->name);
	ft_putendl(":");
	ft_sort_dir(data, tmp->name);
	if (ft_strchr(data->opts, OPT_REV))
		ft_recursive(data, head->left);
	else
		ft_recursive(data, head->right);
}
