/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:04:23 by hjeannin          #+#    #+#             */
/*   Updated: 2014/01/06 22:28:41 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*fresh;

	if (!(fresh = (void *)malloc(sizeof(*fresh) * size)))
		return (NULL);
	ft_memset(fresh, 0, size);
	return (fresh);
}
