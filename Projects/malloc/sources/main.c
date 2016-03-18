/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:42:18 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/17 15:50:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

#include <stdio.h>
#include <sys/mman.h>

void		*tiny_malloc(void)
{
	char	*addr;

	addr = NULL;
	if (!g_data.tiny_start || g_data.tiny_current >= TINY_COUNT)
	{
		addr = mmap(NULL, (size_t)TINY, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
		if (addr)
		{
			printf("tiny malloc %p - size (%li)\n", addr, (size_t)TINY);
			g_data.tiny_start = addr;
			g_data.tiny_current++;
			return (addr);
		}
	}
	return (g_data.tiny_start + g_data.tiny_current * TINY_COUNT);
}

void		*malloc(size_t size)
{
	printf("malloc size : %li\n", size);
	if (size <= (size_t)N)
		tiny_malloc();
	else if (size <= (size_t)M)
		printf("small\n");
	else
		printf("large\n");
	(void)size;
	return (NULL);
}

int			main(void)
{
	printf("%i %i\n", TINY, SMALL);
	printf("%i\n", getpagesize());
	char * s = (char*)malloc(sizeof(char) * 25);
	int i = 0;
	while (i < 25)
	{
		s[i] = 'a' + i;
		printf("s[i] %c\n", s[i]);
		i++;
	}
	printf("%s\n", s);
	return (0);
}
