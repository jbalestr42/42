/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:19:49 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/25 21:46:20 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sh.h>

char				**ft_list_to_array(t_list *list)
{
	t_elem			*tmp;
	char			**array;
	int				i;

	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * list->size + 1)))
		return (0);
	tmp = list->begin;
	while (tmp)
	{
		array[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	array[i] = '\0';
	return (array);
}
