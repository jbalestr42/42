/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:59:26 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/02 18:59:40 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define BUFF_SIZE		10

# include <unistd.h>
# include <stdlib.h>

typedef struct			s_buf
{
	char				c;
	struct s_buf		*next;
}						t_buf;

int						get_next_line(int const fd, char **line);
void					ft_bzero(void *s, size_t n);
char					*ft_strchr(const char *s, int c);

#endif
