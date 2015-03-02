/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:58:28 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/07 12:45:23 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define MAX_VALUE		8192
# define BUFF_SIZE		MAX_VALUE
# define GNL_ERROR		-1
# define GNL_SUCCESS	1
# define GNL_EOF		0

typedef struct	s_buff
{
	char		buf[BUFF_SIZE];
	int			read;
	int			index;
	int			fd;
}				t_buff;

int		get_next_line(int const fd, char **line);

#endif /* FT_GET_NEXT_LINE_H */
