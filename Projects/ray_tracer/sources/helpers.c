/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:48:16 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:12:04 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ray_tracer.h"

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void		ft_putstr(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		write(1, &s[i++], 1);
}

char		*ft_strdup(char *s)
{
	char	*s2;
	int		len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*s)
		*s2++ = *s++;
	*s2 = '\0';
	return (s2 - len);
}

void		ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	c = '0' + n % 10;
	write(1, &c, 1);
}
