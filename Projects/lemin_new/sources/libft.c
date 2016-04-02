/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 20:10:37 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/13 20:10:47 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*tmp;
	int			i;

	i = 0;
	tmp = (char *)malloc(sizeof(s) * len);
	if (tmp)
	{
		while (len--)
		{
			tmp[i] = s[start];
			start++;
			i++;
		}
		tmp[i] = 0;
		return (tmp);
	}
	return (NULL);
}

int				ft_atoi(char *str)
{
	int			total;
	int			is_neg;

	total = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if ((is_neg = *str == '-' ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		total = (total * 10) + (*str++ - '0');
	return (total * is_neg);
}

int				ft_isdigit(int c)
{
	if (c >= (unsigned char)'0' && c <= (unsigned char)'9')
		return (1);
	return (0);
}

int				ft_strlen(char const *s)
{
	int			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
