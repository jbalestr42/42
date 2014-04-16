/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:45:53 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/16 17:52:38 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <stdlib.h>
# include <libft.h>

# define CURRENT_DIR		"."
# define HIDE_FILE			'.'
# define WILD_CARD			'*'
# define OPT_START			'-'
# define NB_OPTS			5
# define OPTS				"Raltr"
# define OPT_REC			'R'
# define OPT_A				'a'
# define OPT_L				'l'
# define OPT_T				't'
# define OPT_REV			'r'
# define FALSE				0
# define TRUE				1

# define MINORBITS			20
# define MINORMASK			((1U << MINORBITS) - 1)
# define MAJOR(dev)			((unsigned int) ((dev) >> (MINORBITS + 4)))
# define MINOR(dev)			((unsigned int) ((dev) & MINORMASK))

typedef int					t_bool;
typedef struct stat			t_stat;
typedef struct dirent		t_dirent;
typedef struct timespec		t_timespec;

typedef struct	s_data
{
	char		**params;
	int			nb_params;
	char		opts[NB_OPTS];
}				t_data;

typedef struct	s_param
{
	char		*name;
	char		*user;
	char		*group;
	mode_t		st_mode;
	nlink_t		st_nlink;
	off_t		st_size;
	time_t		tv_sec;
	blkcnt_t	st_blocks;
	dev_t		st_rdev;
}				t_param;

int				ft_cmp_name(void *c1, void *c2);
int				ft_cmp_date(void *c1, void *c2);
void			ft_param_del(void *content, size_t content_size);
void			ft_recursive(t_data *data, t_avl *head);
void			ft_print(t_data *data, t_avl *head);
void			ft_print_helper(t_avl *head, int len[5]);
void			ft_print_full_param(t_avl *head, int len[4]);
void			ft_print_ls(t_avl *head, int len[4]);
void			ft_print_ls_rev(t_avl *head, int len[4]);
void			ft_print_link(t_param *param, int len_link);
void			ft_print_size(t_param *param, int len_size);
void			ft_print_user(t_param *param, int len_name);
void			ft_print_group(t_param *param, int len_group);
void			ft_print_time(time_t timestamp);
void			ft_print_param(t_avl *node);
void			ft_print_param_l(t_param *param);
void			ft_print_space(int len, int len_max);
int				ft_intlen(int nb);
char			ft_get_file_type(mode_t mode);
void			ft_error(int num_error, int type_error,
		char *param, t_bool b_exit);
void			ft_error_illegal_option(char *param);
void			ft_data_del(t_data *data);
t_data			*ft_data_new(int nb_params);
t_param			*ft_param_new(t_data *data, char *path, char *name);
void			ft_param_new_helper(t_param **param,
		t_stat file_stat, t_data *data);
t_bool			ft_dir_isvalid(t_avl *tmp, char *name);
void			ft_add_file(t_data *data, char *path, char *name, t_avl **file);
void			ft_add_dir(t_data *data, char *path, char *name, t_avl **dir);
void			ft_sort_dir(t_data *data, char *param);
void			ft_ls(t_data *data);
void			ft_get_size(t_avl *head, int *size);
void			ft_max_len_link(t_avl *head, int *len);
void			ft_max_len_size(t_avl *head, int *len);
void			ft_max_len_user(t_avl *head, int *len);
void			ft_max_len_group(t_avl *head, int *len);
t_data			*ft_eval_option(char *s, t_data *data, int *opt);
t_data			*load_options(int argc, char **argv);

#endif
