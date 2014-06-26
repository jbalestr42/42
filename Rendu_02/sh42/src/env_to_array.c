/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:07:52 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/25 21:35:19 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sh.h>

char			**ft_env_to_array(t_list *envi)
{
	t_elem		*tmp;
	char		**array;
	int			i;

	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * envi->size + 1)))
		return (NULL);
	tmp = envi->begin;
	while (tmp)
	{
		array[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
	array[i] = '\0';
	return (array);
}
