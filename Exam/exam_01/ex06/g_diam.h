/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/30 17:53:45 by exam              #+#    #+#             */
/*   Updated: 2014/01/30 18:20:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_DIAM_H
# define G_DIAM_H

# define MAX	1024	

typedef struct		s_vertex
{
	int				a;
	int				b[MAX];
	int				current;
	int				prev[MAX];
	struct s_vertex	*next;
}					t_vertex;

#endif /* !G_DIAM_H */
