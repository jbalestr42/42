/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:03:12 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:03:17 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>

int			ft_check_redir(char *cmd, int *i)
{
	if (cmd[*i] == '<')
		return (CLEFT);
	if (cmd[*i] == '>' && cmd[(*i) + 1] == '>')
		return (CDRIGHT);
	if (cmd[*i] == '>')
		return (CRIGHT);
	return (-1);
}
