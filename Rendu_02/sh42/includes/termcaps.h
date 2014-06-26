/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 14:49:43 by fcorbel           #+#    #+#             */
/*   Updated: 2014/06/26 15:07:33 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <termios.h>
# include <termcap.h>

# define NB_KEYS	11
# define KEY_LENGTH	6

typedef struct termios	t_term;
typedef struct winsize	t_winsize;
typedef struct s_data	t_data;

typedef int				(*t_key)(t_data *data, char key[KEY_LENGTH]);

typedef struct			s_char
{
	char				c;
	struct s_char		*next;
	struct s_char		*prev;
}						t_char;

typedef struct			s_line
{
	int					n;
	t_char				*line;
	struct s_line		*next;
	struct s_line		*prev;
}						t_line;

int						init(t_data *data);
void					init_term(t_term *term);
void					reset_term(t_term *term);
void					init_tab_keys(t_data *data);
int						init_history(t_data *data);
int						save_history(t_data *data);
int						k_up(t_data *data, char key[KEY_LENGTH]);
int						k_down(t_data *data, char key[KEY_LENGTH]);
int						k_right(t_data *data, char key[KEY_LENGTH]);
int						k_left(t_data *data, char key[KEY_LENGTH]);
int						k_enter(t_data *data, char key[KEY_LENGTH]);
int						k_delete(t_data *data, char key[KEY_LENGTH]);
int						k_suppr(t_data *data, char key[KEY_LENGTH]);
int						k_home(t_data *data, char key[KEY_LENGTH]);
int						k_end(t_data *data, char key[KEY_LENGTH]);
int						k_shift_left(t_data *data, char key[KEY_LENGTH]);
int						k_shift_right(t_data *data, char key[KEY_LENGTH]);
int						k_ctrl_d(t_data *data, char key[KEY_LENGTH]);
int						k_other(t_data *data, char key[KEY_LENGTH]);
int						read_keys(t_data *data);
int						tputs_char(int c);
void					signal_action(int signal);

void					add_list_char(t_char **begin, t_char *new, int pos);
t_char					*new_char(char c);
void					print_list_char(t_char *begin, int pos);
void					add_list_line(t_line **begin, t_line *new);
t_line					*new_line(t_char *line);
char					*convert_line(t_data *data);
void					clear_line(t_data *data);
t_char					*copy_line(t_char *c);
void					free_line(t_char *c);
int						count_char(t_char *c);
int						remove_char(t_data *data, t_char **begin, int pos);

#endif
