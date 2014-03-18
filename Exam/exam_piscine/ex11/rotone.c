/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/05 13:54:50 by exam              #+#    #+#             */
/*   Updated: 2013/10/05 14:00:33 by exam             ###   ########.fr       */
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
			c++;
		else if (c == 'z')
			c = 'a';
		else if (c >= 'A' && c <= 'Y')
			c++;
		else if (c == 'Z')
			c = 'A';
		write(1, &c, 1);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
