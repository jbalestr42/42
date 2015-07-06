/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdiam.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/20 10:05:12 by exam              #+#    #+#             */
/*   Updated: 2014/03/20 11:00:42 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDIAM_H
# define GDIAM_H

typedef struct		s_node
{
	int				val;
	int				*neigh;
	int				nb_neigh;
	struct s_node	*next;
}					t_node;

typedef struct		s_path
{
	int				*nodes;
	int				nb_node;
	int				max;
}					t_path;

#endif /* !GDIAM_H */
