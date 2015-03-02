/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:13:17 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/18 15:35:13 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Keys
*/
# define ESC			65307
# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364
# define PLUS			65451
# define MINUS			65453

/*
** Color
*/
# define RED			0x990000

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define BUFF_SIZE		4096
# define ORIGIN_X		1000
# define ORIGIN_Y		80
# define STEP_X			50
# define STEP_Y			50
# define WIDTH			1080
# define HEIGHT			720
# define CST_1			0.5
# define CST_2			0.5
# define ABS(x)			((x) < 0 ? -(x) : (x))

typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;

typedef struct		s_line
{
	char			*str;
	struct s_line	*next;
}					t_line;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_point			***points;
	int				*size;
	int				nb_line;
	t_point			cam;
	float			scale;
}					t_env;

/*
** Helpers
*/
int			ft_isdigit(int c);
char		*ft_strsub(const char *, unsigned int start, unsigned int len);
t_point		**ft_intsplit(const char *s, int nb_line, int *elem);
int			ft_atoi(char const *str);
int			get_next_line(int fd, char **line);
t_line		*ft_lstnew(char *line);
t_line		*ft_lstpushback(t_line **head, t_line *new);
t_env		*ft_envnew(void);
void		ft_envdel(t_env *e);
t_env		*ft_initpoints(t_env *e, t_line **head);

/*
** Draw
*/
void		ft_draw_line(t_env *e, t_point p1, t_point p2);
void		ft_draw_rect(t_env *e, t_point *p1, t_point *p2);
void		ft_draw_map(t_env *e);

/*
** Compute projections
*/
t_point		ft_get_point(t_env *e, t_point *pt, t_point (*f)(int, int, int));
t_point		ft_para(int x, int y, int z);
t_point		ft_iso(int x, int y, int z);

/*
** Events
*/
int			key_hook(int keycode, t_env *e);
int			expose_hook(t_env *e);
int			mouse_hook(int x, int y, t_env *e);

#endif /* !FDF_H */
