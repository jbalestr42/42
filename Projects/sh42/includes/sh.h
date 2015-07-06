/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 18:31:09 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/26 15:05:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <d_list_tools.h>
# include "termcaps.h"

int					g_sep_size[SEP_MAX];

typedef struct		s_cmds
{
	char			*str;
	int				(*func)(char **c, t_list *envi);
}					t_cmds;

typedef struct		s_data
{
	t_list			*envi;
	t_list			*cmds;
	t_term			term;
	t_key			keys[NB_KEYS];
	int				cursor;
	int				c_y;
	int				nb_c;
	t_line			*history;
	t_line			*last;
	char			*line;
}					t_data;

t_data				*g_data;

int					ft_parse(char *line, t_data *data);
void				ft_free_array(char **c);
char				**ft_clean_array(char **a);
int					ft_init_data(t_list *envi, char **environ);
char				*ft_getpost(void);
void				ft_prompt(void);
char				**ft_str_to_tab(char *line);

/*
** Shell Init
*/

char				**ft_strsplit2(char const *s, char c, char c2);
void				ft_rm_end_sc(char **a);
void				ft_split_semicolon(char **c, t_list *envi);
int					ft_shell_init(t_data *data);
int					ft_execute_cmds(t_data *data);
int					ft_execute_cmd(t_bloc *bloc, t_data *data);

/*
** Built in
*/

int					ft_check_built_in(char **c);
void				ft_built_in(t_bloc *bloc, t_list *envi);
int					ft_env(char **c, t_list *envi);
int					ft_cd(char **c, t_list *envi);
int					ft_setenv(char **c, t_list *envi);
int					ft_unsetenv(char **c, t_list *envi);
int					ft_echo(char **c, t_list *envi);
int					ft_history(char **c, t_list *envi);
int					ft_exit(char **cmd, t_list *envi);

/*
** Execve
*/

int					ft_pre_exec(t_bloc *bloc, t_list *envi);
int					ft_check_execve(char **c, t_list *envi);
int					ft_exec(t_bloc *bloc, t_list *envi);
char				*ft_check_exist(char *str);
char				*ft_find_cmd_path(char *str, t_list *envi);

/*
** Envi Tools
*/

char				*ft_find_in_envi(t_list *envi, char *search);
char				**ft_env_to_array(t_list *envi);
int					ft_replace_line(t_list *envi, char *search, char *line);
void				ft_remove_line(t_list *envi, char *search);
int					ft_exist_in_envi(t_list *envi, char *search);

/*
**  Tools
*/

int					ft_check_fitenvi(char *str);
char				*ft_trim_search(char *search);
void				ft_print_array(char **a);
char				**ft_list_to_array(t_list *list);
int					ft_print_error(char *error);
void				ft_debug_print_bloc(t_bloc *bloc);

/*
**  Parser
*/

int					ft_check_sep(char *line, int i);
char				*ft_get_bloc(char *line, int *i);
int					ft_fill_bloc(t_list *cmds, char *new_bloc);
char				*ft_clean_line(char *old);
int					ft_find_cmd(char *line, t_list *envi);

/*
**  Error bitch
*/

int					ft_entry_error(char *str);
int					ft_check_parse_error(t_list *cmds);
int					ft_print_parse_error(char *error);

/*
**  Redir
*/

int					ft_check_redir(char *cmd, int *i);
int					ft_get_redir(char *cmd);
int					ft_parse_redir_type(t_bloc *bloc, t_data *data);
int					ft_parse_redir_1(t_bloc *bloc);
int					ft_parse_redir_2(t_bloc *bloc, int space);
void				ft_get_dup(t_bloc *bloc);
int					ft_get_cmd_size(char *bloc, int *i);
int					ft_get_file_size(char *bloc, int *i);
char				*ft_copy_cmd(char *bloc, char *cmd, int i, int cmd_size);
char				*ft_copy_file(char *bloc, char *file, int i, int file_size);
int					ft_open_redir(t_bloc *bloc, char *file);
int					ft_pipe(t_elem *elem, t_data *data);
int					ft_exec_redir(t_bloc *bloc, t_data *data);

#endif
