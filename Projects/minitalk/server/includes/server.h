/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 11:03:46 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 18:05:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>

# define O_SIZE		8
# define DEBUG		0

typedef struct			s_word
{
	char				c;
	struct s_word		*next;
}						t_word;

typedef struct			s_client
{
	int					pid;
	int					byte[8];
	int					current;
	int					receiving;
	int					last;
	int					time;
	t_word				*current_word;
	t_word				*words;
	struct s_client		*next;
}						t_client;

typedef struct			s_data
{
	struct sigaction	sa;
	int					pid;
	t_client			*clients;
}						t_data;

t_data		*get_data(void);
void		add_byte(t_client *client);
void		print_word(t_client *client);
void		set_bit(t_client *client, int val);
void		signal_usr(int signal, siginfo_t *siginfo, void *context);
void		signal_usr1(t_client *client);
void		signal_usr2(t_client *client);
t_client	*find_client(t_client **begin, int pid);
t_word		*new_word(char c);
void		push_word(t_client *client, t_word *new);

#endif /* !SERVER_H */
