/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:08:26 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:08:27 by jbalestr         ###   ########.fr       */
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

# define USAGE		"usage: ft_select choice1 choice2...\n"
# define EMPTY		"empty environment.\n"

typedef struct termios		t_termios;
typedef struct winsize		t_winsize;

typedef struct		s_word
{
	int				sel;
	int				und;
	int				size;
	char			*str;
	struct s_word	*next;
	struct s_word	*prev;
}					t_word;

typedef struct		s_data
{
	t_termios		term;
	t_termios		buterm;
	char			buffer[2048];
	t_word			*words;
	int				maxl;
	int				maxc;
	int				maxwpp;
	int				current;
	int				cpage;
	int				tpage;
	int				size;
	int				tsel;
	int				colwid;
}					t_data;

void				tputll(t_data *data);
void				display(t_data *data);

void				sigsegv(int signum);
void				sigctrlc(int signum);
void				sigctrlz(int signum);
void				sigwinch(int signum);
void				sigfg(int signum);

int					error(int quit, char *msg, t_data *data);
void				flags(t_termios *term);
void				tinit(t_data *data);
void				winit(int argc, char **argv, t_word *word);
void				init(int argc, char **argv, t_data *data);

int					wsize(t_data *data);
void				reinit(void);
t_data				*datast(void);
void				ft_select(t_data *data);
t_word				*curword(t_data *data);

void				treset(t_data *data);
int					is_esc(t_data *data, char *key);
void				is_space(t_data *data, char *key);
int					is_del(t_data *data, char *key);
int					is_enter(t_data *data, char *key);

void				is_prevp(t_data *data, char *key);
void				is_nextp(t_data *data, char *key);
void				is_minus(t_data *data, char *key);
void				is_plus(t_data *data, char *key);

void				is_left(t_data *data, char *key);
void				is_right(t_data *data, char *key);
void				is_up(t_data *data, char *key);
void				is_down(t_data *data, char *key);

void				tputword(int underline, int reverse, char *str);
void				tputnbr(int nb);
int					tputchar(int c);
void				tputstr(char *str);
void				tputcutstr(char *str, int size);

void				ft_putstr(char *str);
void				ft_putendl(char *str);
int					ft_strlen(char *str);

#endif
