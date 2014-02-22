/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/02 20:28:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <SDL/SDL.h>

# define NB_KEY_EVENT	7
# define WIDTH			320
# define HEIGHT			200
# define NAME			"Wolf 3D"
# define ABS(x)			((x) < 0 ? -(x) : (x))

/* Keys */
# define ESC			65307
# define LEFT			65361
# define UP				65362
# define RIGHT			65363
# define DOWN			65364
# define PLUS			65451
# define MINUS			65453

typedef struct s_env	t_env;
typedef void			(key_event)(t_env *e);

typedef struct			s_key
{
	int					keycode;
	key_event			*exec_event;

}						t_key;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

struct					s_env
{
	SDL_Surface			*screen;
	t_point				***points;
	int					*size;
	int					nb_line;
	t_key				key_events[NB_KEY_EVENT];
};

/* Hooks */
int		key_hook(int keycode, t_env *e);
int		expose_hook(t_env *e);
int		mouse_hook(int x, int y, t_env *e);
int		loop_hook(t_env *e);

/* Key events */

/* Draw */
void	ft_draw_line(t_env *e, t_point p1, t_point p2);

/* Helpers */
void	ft_envdel(t_env *e);
t_env	*ft_envnew(void);

#endif /* !WOLF_H */
