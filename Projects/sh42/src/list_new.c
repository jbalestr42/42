/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:16:07 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/20 17:18:28 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <stdio.h>
#include <stdlib.h>

t_list		*ft_list_new(void)
{
	t_list		*new;

	new = NULL;
	if (!(new = (t_list *)malloc(sizeof(*new))))
	{
		perror("\033[31;1mft_list_new()\033[0m");
		return (NULL);
	}
	new->size = 0;
	new->begin = NULL;
	new->end = NULL;
	return (new);
}
