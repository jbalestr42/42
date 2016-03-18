/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 14:42:06 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/17 15:47:39 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_HPP
# define MALLOC_HPP

# include <stdlib.h>
# include <unistd.h>

# define N			(128)
# define M			(4096)

# define TINY_COUNT		128
# define SMALL_COUNT	128

# define TINY		(((TINY_COUNT * N) / getpagesize()) * getpagesize())
# define SMALL		(((SMALL_COUNT * M) / getpagesize()) * getpagesize())

typedef struct		s_data
{
	int				tiny_current;
	char			*tiny_start;
}					t_data;

t_data	g_data;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);
void	show_alloc_mem();

#endif
