/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:17:53 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:17:53 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					ft_get_cmd_size(char *bloc, int *i)
{
	int				redir;
	int				cmd_size;

	cmd_size = 0;
	while (bloc[*i])
	{
		if ((redir = ft_check_redir(bloc, i)) != -1)
			break ;
		cmd_size++;
		(*i)++;
	}
	(*i)++;
	if (redir == CDRIGHT)
		(*i)++;
	if (bloc[*i] == ' ' || bloc[*i] == '\t')
		(*i)++;
	return (cmd_size);
}
