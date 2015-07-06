#ifndef G_DIAM_H
# define G_DIAM_H

typedef struct		s_node
{
	int				val;
	int				visited;
	int				nb_links;
	struct s_node	*next;
}					t_node;

#endif /* !G_DIAM_H */
