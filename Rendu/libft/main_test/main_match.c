/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_match.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:21:56 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/30 12:41:18 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int		ft_match(char *s1, char *s2);

int		main(void)
{
	printf("------ Match ------\n");
	printf("Retourne 1 (normalement) : ");
	printf("%i\n", ft_match("bonjour", "bonjour"));
	printf("%i\n", ft_match("bonjour", "bonj*"));
	printf("%i\n", ft_match("bonjour", "*bon*"));
	printf("%i\n", ft_match("bonjour", "b*n*o*r"));
	printf("%i\n", ft_match("bonjour", "******"));
	printf("%i\n", ft_match("bonjour", "*"));
	printf("%i\n", ft_match("bonjour", "**j*"));
	printf("%i\n", ft_match("bonjour", "bonj*our"));
	printf("%i\n", ft_match("bonjour", "*b*o*n*j*o*u*r"));
	printf("%i\n", ft_match("fer far", "*f*r"));
	printf("Retourne 0 (normalement) : ");
	printf("%i\n", ft_match("bonjour", "bon*jur"));
	printf("%i\n", ft_match("bonjour", "f*jour"));
	printf("%i\n", ft_match("bonjour", "pas bonjour"));
	printf("%i\n", ft_match("bonjour", "b*jn*o*r"));
	return (0);
}
