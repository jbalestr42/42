/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/26 20:39:01 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/23 17:42:06 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_LIST_TOOLS_H
# define D_LIST_TOOLS_H

# define SEMICOLON			0
# define PIPE				1
# define AND				2
# define OR					3

# define SEMICOLON_SIZE		1
# define PIPE_SIZE			1
# define AND_SIZE			2
# define OR_SIZE			2

# define SEP_MAX			4

# define CLEFT				10
# define CRIGHT				11
# define CDRIGHT			12

# define TYPE_DATA			0
# define TYPE_CMD			1

# define EXEC				42
# define BLTI				43

typedef struct				s_bloc
{
	int						was_redir;
	int						redir;
	int						fd;
	char					**tcmd;
	char					*cmd;
	int						sep_prev;
	int						sep_next;
	int						success;
	int						cmd_type;
}							t_bloc;

typedef struct				s_elem
{
	int						type;
	char					*data;
	t_bloc					*bloc;
	struct s_elem			*next;
	struct s_elem			*prev;
}							t_elem;

typedef struct				s_list
{
	unsigned int			size;
	t_elem					*begin;
	t_elem					*end;
}							t_list;

t_list						*ft_list_new(void);
t_elem						*ft_list_create_elem(int type);
void						ft_list_clear_elem(t_elem *elem);
t_list						*ft_list_push_back(t_list *list, t_elem *elem);
void						ft_list_clear(t_list **list);
t_list						*ft_list_del_elem(t_list *current_list,
												t_elem *del_elem);
t_list						*ft_list_init(t_list *list);
void						ft_list_print(t_list *list);

#endif
