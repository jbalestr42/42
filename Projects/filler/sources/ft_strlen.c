/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:27:40 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/22 15:14:48 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

unsigned int		ft_strlen(char const *s)
{
	unsigned int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
