/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:45:37 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 15:45:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "ft_ls.h"

/*
** Error types
*/
# define STR_ERROR	1
# define OPT_ERROR	2

/*
** Creating a table for each error code
*/
# define NOT_ENOUGH_MEM	12
# define NO_SUCH_FILE	2
# define ILLEGAL_OPTION	0

void	ft_error(int num_error, int type_error, char *param, t_bool b_exit);
void	ft_error_illegal_option(char *param);

#endif /* FT_ERROR_H */
