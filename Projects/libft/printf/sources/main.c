/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 00:13:54 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:25:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX		2147483648

int		main(void)
{
	int		i = 0, j = 0;
	char	*d;
	int		tmp[1];

	tmp[0] = -1;
	ft_printf("s");
	ft_printf("%s", "\n");
	ft_printf("s");
	i = ft_printf("%\t%\t%\t%\t");
	ft_printf("%i : ", i);
	ft_printf("%\n");
	ft_printf("Un nid de pourcentage %%%, %%, %i\n", 123);
	ft_printf("%d is for the %s\n", 42, "Braves.");
	ft_printf("A : %c (%i)\n", 'A', 'A');
	ft_printf("%d%d%s%s", 4, 2, " is for", " the Braves.\n");
	i = MAX;
	j = -i;
	printf("   printf : %u | %u | %u | %u\n", 42, -42, i, j);
	ft_printf("ft_printf : %u | %u | %u | %u\n", 42, -42, i, j);
	printf("   printf : %o | %o | %o | %o\n", 42, -42, i, j);
	ft_printf("ft_printf : %o | %o | %o | %o\n", 42, -42, i, j);
	printf("   printf : %x | %X | %x | %X\n", 42, -42, i, j);
	ft_printf("ft_printf : %x | %X | %x | %X\n", 42, -42, i, j);
	d = (char *)malloc(sizeof(char) * 15);
	d[14] = '\0';
	i = printf("   printf : %p | %p | %p\n", NULL, d, tmp);
	j = ft_printf("ft_printf : %p | %p | %p\n", NULL, (long unsigned int)d, tmp);
	ft_printf("printf : %i | ft_printf : %i\n", i, j);
	ft_printf("bin : %b | %b | %b\n", 1235, d, 12);
	free(d);

	int		test;
	char	*str_test, *str_test2;
	void	*p, *p2, *p3, *p4;
	void	*ptr = NULL, *ptr1 = NULL;

	ptr += 9223372036854775807;
	ptr1 -= 9223372036854775807;
	str_test = "couesf4y45re\tcou";
	str_test2 = NULL;
	test = 0;

	p = &test;
	p2 = &str_test;
	p3 = &str_test2;
	p4 = p3;
	ft_putnbr(ft_printf("ft_printf : %p %p %p %p %p %p\n", p, p2, p3, p4, ptr, ptr1));
	ft_putchar('\n');
	ft_putnbr(printf("   printf : %p %p %p %p %p %p\n", p, p2, p3, p4, ptr, ptr1));
	ft_printf("%Z\n", 456);
	i = ft_printf("  %-+-+-14d | % -8d | %     d | %+5d | %5d\n", 12,  456, 4, 20, 20);
	j = printf("  %-+-+-14d | % -8d | %     d | %+5d | %5d\n", 12,  456, 4, 20, 20);
	ft_printf("%i - %i\n", i, j);
	i = ft_printf("% 0 8d | %08d\n", 456, 456);
	j = printf("% 0 8d | %08d\n", 456, 456);
	ft_printf("%i - %i\n", i, j);
	ft_putchar('\n');
	ft_printf("bonjour %\n bye\n");
	
	ft_printf("%f | %f | %f | %f", 123.25, 123.32, -123.32, 123.6521324785);
	ft_putchar('\n');
	printf("%f | %f | %f | %f", 123.25, 123.32, -123.32, 123.6521324785);
	printf("\n%#o | %o", 123, 123);
	printf("\n%#x | %x", 123, 123);
	printf("\n%#X | %X", 123, 123);
	printf("\n%#f | %f", 123.12, 123.12);
	printf("\n%#e | %e", 123.12, 123.12);
	printf("\n%#E | %E", 123.12, 123.12);
	printf("\n%#g | %g", 123.12124124, 123.12124124);
	printf("\n%#G | %G", 123.12124124, 123.12124124);
	printf("\n%#g | %g", 123.12, 123.12);
	printf("\n%#G | %G", 123.12, 123.12);
	return (0);
}
