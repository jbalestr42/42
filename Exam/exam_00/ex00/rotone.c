/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/16 14:50:14 by exam              #+#    #+#             */
/*   Updated: 2014/01/16 18:07:21 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rotone(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'a' && c <= 'y')
			c = c + 1;
		else if (c == 'z')
			c = 'a';
		if (c >= 'A' && c <= 'Y')
			c = c + 1;
		else if (c == 'Z')
			c = 'A';
		write(1, &c, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
