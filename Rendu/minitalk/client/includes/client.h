/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 11:35:35 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 18:46:22 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# define O_SIZE		8
# define WAIT		15

typedef struct		s_data
{
	int				server_pid;
	int				valid;
}					t_data;

int					ft_atoi(const char *s);
void				check_line(void);
void				send_message(char *message);
#endif /* !CLIENT_H */
