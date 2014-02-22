/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:08:30 by csalmon-          #+#    #+#             */
/*   Updated: 2013/12/31 19:54:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char const *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (s2 - len);
}

int		main(int argc, char **argv, char **arge)
{
	if (!arge || !(arge[0]))
	{
		if (open(argv[1], O_RDONLY) > 0)
		{
			open(argv[4], O_CREAT | O_TRUNC | O_WRONLY,
					S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR);
		}
		return (1);
	}
	if (argc != 5)
	{
		ft_putstr("Function requires 4 arguments.\n", 2, 0);
		ft_putstr("usage: ./pipex [file1] [cmd1] [cmd2] [file2]", 2, 1);
		return (1);
	}
	if (!*argv[2])
		argv[2] = ft_strdup("cat");
	if (!*argv[3])
		argv[3] = ft_strdup("cat");
	pipex(argv, arge);
	return (0);
}
