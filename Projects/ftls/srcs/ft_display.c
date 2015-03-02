/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:43:44 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/16 17:48:59 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	ft_print(t_data *data, t_avl *head)
{
	int		len[5];
	int		i;

	i = -1;
	while (++i < 5)
		len[i] = 0;
	if (!ft_strchr(data->opts, OPT_L))
	{
		if (ft_strchr(data->opts, OPT_REV))
			ft_avliter_inorderrev(head, &ft_print_param);
		else
			ft_avliter_inorder(head, &ft_print_param);
		return ;
	}
	if (!head)
		return ;
	ft_print_helper(head, len);
	if (ft_strchr(data->opts, OPT_REV))
		ft_print_ls_rev(head, len);
	else
		ft_print_ls(head, len);
}

void	ft_print_helper(t_avl *head, int len[5])
{
	ft_get_size(head, &len[4]);
	ft_max_len_link(head, &len[0]);
	ft_max_len_user(head, &len[1]);
	ft_max_len_group(head, &len[2]);
	ft_max_len_size(head, &len[3]);
	len[0] = ft_intlen(len[0]);
	len[3] = ft_intlen(len[3]);
	ft_putstr("total ");
	ft_putnbr(len[4]);
	ft_putchar('\n');
}

void	ft_print_full_param(t_avl *head, int len[4])
{
	t_param		*param;

	param = (t_param *)head->content;
	ft_print_param_l(param);
	ft_print_link(param, len[0]);
	ft_print_user(param, len[1]);
	ft_print_group(param, len[2]);
	ft_print_size(param, len[3]);
	ft_print_time(param->tv_sec);
	ft_putendl(param->name);
}

void	ft_print_ls(t_avl *head, int len[4])
{
	if (!head)
		return ;
	ft_print_ls(head->left, len);
	ft_print_full_param(head, len);
	ft_print_ls(head->right, len);
}

void	ft_print_ls_rev(t_avl *head, int len[4])
{
	if (!head)
		return ;
	ft_print_ls_rev(head->right, len);
	ft_print_full_param(head, len);
	ft_print_ls_rev(head->left, len);
}
