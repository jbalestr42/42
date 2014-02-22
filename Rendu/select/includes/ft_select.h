/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/12 18:40:47 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/12 18:44:39 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include "libft.h"

# define KEYS		4
# define USAGE		"usage: ft_select choixe1 choice2...\n"
# define EMPTY		"empty environment.\n"

typedef struct termios		t_termios;
typedef struct winsize		t_winsize;

typedef struct		s_key
{
	char			*key;
	int				(*f)(char *str);
}					t_key;

typedef struct		s_word
{
	int				sel;
	int				und;
	int				size;
	char			*str;
}					t_word;

typedef struct		s_col
{
	int				index;
	int				width;
	struct s_col	*next;
}					t_col;

typedef struct		s_data
{
	t_termios		term;
	char			buffer[2048];
	t_word			*words;
	t_col			*columns;
	int				current;
	int				size;
	int				deleted;
	t_key			keys[KEYS];
	char			*ret;
}					t_data;

/* Term functions */
void	flags(t_termios *term);
void	reset(t_data *data);
void	init(int argc, char **argv, t_data *data);
void	term_putstr(int underline, int reverse, char *str);
int		tputs_putchar(int c);

void	display(t_data *data);

/* Key functions */
void	ft_select(t_data *data);

/* Helpers */
int		error(int quit, char *msg, t_data *data);

#endif
