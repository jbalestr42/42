/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 21:24:32 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/06 15:18:39 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10000

int		get_next_line(int const fd, char **line);
char	*ft_strchrsub(char *s, char c);
int		instanciate_line(char **buff, char **line);

#endif /* !GET_NEXT_LINE_H */
