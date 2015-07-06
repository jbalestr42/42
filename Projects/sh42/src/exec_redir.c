/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:32:47 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/23 21:32:47 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_exec_redir(t_bloc *bloc, t_data *data)
{
	bloc->was_redir = bloc->redir;
	if (!ft_execute_cmd(bloc, data))
		return (0);
	return (1);
}
