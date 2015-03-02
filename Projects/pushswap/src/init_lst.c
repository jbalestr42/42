/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:18:51 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/28 21:52:30 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>

t_lst	*lst_new(int val)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->val = val;
	new->next = NULL;
	return (new);
}

void	lst_del(t_lst *head)
{
	t_lst	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}
}

void	lst_pushfront(t_lst **head, t_lst *new)
{
	if (!new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	lst_pushback(t_lst **head, t_lst *new)
{
	t_lst	*tmp;

	if (!new)
		return ;
	if (*head == NULL)
		*head = new;
	else
	{
		tmp = *head;
		while (tmp)
			tmp = tmp->next;
		tmp = new;
	}
}
