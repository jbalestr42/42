/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 13:58:19 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/28 21:52:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct		s_lst
{
	int				val;
	struct s_lst	*next;
}					t_lst;

/*
** Helpers
*/
int			ft_atoi(const char *str);
t_lst		*lst_new(int val);
void		lst_pushfront(t_lst **head, t_lst *new);
void		lst_pushback(t_lst **head, t_lst *new);
void		lst_del(t_lst *head);

/*
** Main functions
*/
void		swap_s(t_lst **l_a, t_lst **l_b);
int			swap_a(t_lst **l_a);
int			swap_b(t_lst **l_b);
void		pswap_a(t_lst **l_a, t_lst **l_b);
void		pswap_b(t_lst **l_a, t_lst **l_b);
int			rotate_r(t_lst **l_a, t_lst **l_b);
int			rotate_a(t_lst **l_a);
int			rotate_b(t_lst **l_b);
int			rrotate_r(t_lst **l_a, t_lst **l_b);
int			rrotate_a(t_lst **l_a);
int			rrotate_b(t_lst **l_b);

#endif /* !PUSHSWAP_H */
