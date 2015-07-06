/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:20:27 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/21 16:13:53 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define STD_IN		0
# define COMMENT	'#'
# define START		"##start"
# define END		"##end"

typedef struct s_path	t_path;

/*
** Struct used to read std in
*/
typedef struct		s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

/*
** Room state : EMPTY | FULL
*/
typedef enum		e_state
{
	EMPTY, FULL
}					t_state;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

/*
** name : room's name
** pos : room's coordinate
** state : room's state
** neighbour : neighbours
*/
typedef struct		s_room
{
	char			*name;
	t_coord			pos;
	int				state; // t_state ?
	t_path			*neighbour;
}					t_room;

/*
** room : current room
** pheromone : pheromone between this room and previous room
** next : next neighbour
*/
struct				s_path
{
	t_room			*room;
	double			phero;
	struct s_path	*next;
};

typedef struct		s_plist
{
	t_path			*path;
	struct s_plist	*next;
}					t_plist;

/*
** cur : current room
** path : path from start to end
*/
// ajouter une liste de piece visitée
typedef struct		s_ant
{
	int				num;
	int				displayed;
	t_room			*cur;
	t_plist			*path;
}					t_ant;

/*
** nb_ant : ant number
** ants : *t_ant tab
** start : first room
** end : last room
** rooms : all rooms
*/
typedef struct		s_env
{
	int				nb_ant;
	t_ant			**ants;
	t_room			*start;
	t_room			*end;
	t_path			*rooms;
}					t_env;


/*
** Init
*/
t_env		*init_env(void);
int			init_graph(t_env *e);
int			init_ants(t_env *e);
int			read_ants(t_env *e, t_line **line);
int			read_rooms(t_env *e, t_line **line);
int			read_paths(t_env *e, t_line **line);
t_line		*read_std(void);
void		find_path(t_env *e);

/*
** Helpers
*/
int			ft_strlen_tab(char **tab);
int			ft_free_tab(char **tab);
int			valid_nbr(char *s, int neg);
void		next_line(t_line **line);

#endif /* !LEMIN_H */
