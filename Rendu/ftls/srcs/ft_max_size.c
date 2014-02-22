/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:44:47 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:44:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <libft.h>

void	ft_get_size(t_avl *head, int *size)
{
	if (!head)
		return ;
	*size += ((t_param *)(head->content))->st_blocks;
	ft_get_size(head->left, size);
	ft_get_size(head->right, size);
}

void	ft_max_len_link(t_avl *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ((t_param *)(head->content))->st_nlink;
	*len = tmp < *len ? *len : tmp;
	ft_max_len_link(head->left, len);
	ft_max_len_link(head->right, len);
}

void	ft_max_len_size(t_avl *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ((t_param *)(head->content))->st_size;
	*len = tmp < *len ? *len : tmp;
	ft_max_len_size(head->left, len);
	ft_max_len_size(head->right, len);
}

void	ft_max_len_user(t_avl *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ft_strlen(((t_param *)(head->content))->user);
	*len = tmp < *len ? *len : tmp;
	ft_max_len_user(head->left, len);
	ft_max_len_user(head->right, len);
}

void	ft_max_len_group(t_avl *head, int *len)
{
	int		tmp;

	if (!head)
		return ;
	tmp = ft_strlen(((t_param *)(head->content))->group);
	*len = tmp < *len ? *len : tmp;
	ft_max_len_group(head->left, len);
	ft_max_len_group(head->right, len);
}
