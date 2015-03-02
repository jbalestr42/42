/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:02:53 by jbalestr          #+#    #+#             */
/*   Updated: 2014/05/09 18:02:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

char	*ft_strcpy(char *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s2 || !s1)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpycat(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if ((str = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2))
					+ 2)) == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr(char *str, char out, char n)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(out, &(str[i]), 1);
		i = i + 1;
	}
	if (n != 0)
		write(out, "\n", 1);
}
