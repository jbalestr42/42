/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:25:57 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:25:59 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh.h>

void				ft_print_array(char **a)
{
	int				i;

	if (!a)
		return ;
	i = 0;
	while (a[i])
	{
		ft_putendl_fd(a[i], 2);
		i++;
	}
}
