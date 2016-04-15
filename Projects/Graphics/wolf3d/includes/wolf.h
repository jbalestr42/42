/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2015/07/09 15:20:29 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define PI				3.14159265
# define NB_KEY_EVENT	13
# define NB_WALL		17
# define WIDTH			1580
# define HEIGHT			800
# define NAME			"Wolf 3D"
# define SIZE			256
# define ABS(x)			((x) < 0 ? -(x) : (x))
# define DBL_MAX		999999999999999999
# define SPEED			SIZE / 8
# define SPEED_ROT		4

/*
** Map value
*/
# define EMPTY			0
# define SPAWN			1
# define DOOR			2
# define TRIGGER		3
# define WALL			6
# define DISCO			7
# define CAT			8
# define CAT_LEFT		9
# define CAT_RIGHT		10
# define DOOR_CAT		11
# define REALVES		12
# define MVALLET		13
# define GEXBRAYA		14
# define JBALESTR		15
# define TCHARLAT		16
# define PCIAVALD		17
# define FCORBEL		18
# define EVILEVIL		19
# define GLASSET		20
# define MROUX			21

/*
** Keys
*/
# define ESC			53//65307
# define LEFT			0//65361
# define UP				13//65362
# define RIGHT			2//65363
# define DOWN			1//65364
# define PLUS			65451
# define MOINS			65453
# define KEY_W			119
# define KEY_S			115
# define KEY_A			97
# define KEY_D			100
# define KEY_1			49
# define KEY_2			50
# define KEY_3			51
# define KEY_4			52

/*
** Textures
*/
# define T_WALL			"images/wall.xpm"
# define T_WALLHD		"images/wallhd.xpm"
# define T_DISCO		"images/hip_wall.xpm"
# define T_SKY			"images/sky.xpm"
# define T_SPLASH		"images/splash.xpm"
# define T_WEAPON		"images/weapon.xpm"
# define T_DOOR			"images/door.xpm"
# define T_CAT			"images/cat.xpm"
# define T_CATLEFT		"images/cat_left.xpm"
# define T_CATRIGHT		"images/cat_right.xpm"
# define T_DOORCAT		"images/doorcat.xpm"
# define T_HUD			"images/hudbar.xpm"
# define T_REALVES		"images/portrait/realves.xpm"
# define T_MVALLET		"images/portrait/mvallet.xpm"
# define T_GEXBRAYA		"images/portrait/gexbraya.xpm"
# define T_JBALESTR		"images/portrait/jbalestr.xpm"
# define T_TCHARLAT		"images/portrait/tcharlat.xpm"
# define T_PCIAVALD		"images/portrait/pciavald.xpm"
# define T_FCORBEL		"images/portrait/fcorbel.xpm"
# define T_EVILEVIL		"images/portrait/evillevi.xpm"
# define T_GLASSET		"images/portrait/glasset.xpm"
# define T_MROUX		"images/portrait/mroux.xpm"

typedef struct s_env	t_env;
typedef void			(key_event)(t_env *e);
typedef void			(trigger)(t_env *e);

typedef struct			s_key
{
	int					keycode;
	int					is_press;
	key_event			*event;

}						t_key;

typedef struct			s_point
{
	int					x;
	int					y;
}						t_point;

typedef struct			s_fpoint
{
	double				x;
	double				y;
	int					rgb;
}						t_fpoint;

/*
** Point of view
*/
typedef struct			s_pov
{
	t_point				pos;
	double				alpha;
}						t_pov;

typedef struct			s_img
{
	void				*ptr;
	char				*img;
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
	float				current_frame;
	int					frames;
	int					frame_size;
	int					max_size;
	int					speed;
	int					type;
}						t_img;

/*
** mlx : mlx object
** win : mlx windows
** map : actual map
** fov : field of view
** dist_plan_player : distance between player and projection plan
** current_height : used to calcul vertical view
** dist_size : distance_plan_player * SIZE
** step_angle : angle value between two columns
** pov : point of view
*/
struct					s_env
{
	void				*mlx;
	void				*win;
	t_img				walls[NB_WALL];
	t_img				*current_wall;
	t_img				screen;
	t_img				sky;
	t_img				splash;
	t_img				hud;
	t_img				weapon;
	int					**map;
	int					map_height;
	int					map_width;
	int					height_px;
	int					width_px;
	int					fov;
	int					dist_plan_player;
	int					current_height;
	int					rgb;
	float				last_time;
	float				framerate;
	double				dist_size;
	double				step_angle;
	t_pov				pov;
	t_key				key_events[NB_KEY_EVENT];
	trigger				*trig_event;
};

/*
** Hooks
*/
int			key_hook_press(int keycode, t_env *e);
int			key_hook_release(int keycode, t_env *e);
int			expose_hook(t_env *e);
int			loop_hook(t_env *e);

/*
** Key events
*/
void		init_events(t_env *e);
void		key_event_esc(t_env *e);
void		key_event_left(t_env *e);
void		key_event_right(t_env *e);
void		key_event_plus(t_env *e);
void		key_event_moins(t_env *e);
void		key_event_key_w(t_env *e);
void		key_event_key_s(t_env *e);
void		key_event_key_a(t_env *e);
void		key_event_key_d(t_env *e);
void		key_event_key_1(t_env *e);
void		key_event_key_2(t_env *e);
void		key_event_key_3(t_env *e);
void		key_event_key_4(t_env *e);

/*
** Triggers
*/
void		event_disco(t_env *e);
void		event_normal(t_env *e);

/*
** Draw
*/
void		ft_draw_view(t_env *e);
void		ft_draw_hud(t_env *e, int x);
void		ft_draw_weapon(t_env *e, int x);

/*
** Helpers
*/
int			*ft_intsplit(char const *s, int nb_elem);
int			ft_atoi(const char *str);
void		ft_envdel(t_env *e);
t_env		*ft_envnew(void);
t_img		init_screen(void *mlx, int width, int height);
t_img		init_image(void *mlx, char *path, int width, int height);
void		init_sprite(t_img *img, int nb_frame, int frame_size, int speed);
void		init_sprite_hud(t_img *img, int nb_frame, int size);
int			init_map(t_env *e, char *path);
void		init_walls(t_env *e);
void		compute_pos(t_env *e, t_point *newpos);

/*
** Math
*/
double		ft_degre_to_radian(double degree);
double		ft_cos(double angle);
double		ft_sin(double angle);
double		ft_tan(double angle);
double		ft_square(double nb);
int			column_height(t_env *e, double beta, double *p);

#endif /* !WOLF_H */
