/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:04:53 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:04:54 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char				*ft_copy_cmd(char *bloc, char *cmd, int i, int cmd_size)
{
	int				k;
	int				j;

	if (!(cmd = (char *)malloc(sizeof(char) * cmd_size + 1)))
	{
		perror("ft_copy_cmd()");
		return (NULL);
	}
	j = 0;
	k = i;
	while (i < k + cmd_size)
	{
		cmd[j] = bloc[i];
		i++;
		j++;
	}
	cmd[cmd_size] = '\0';
	return (cmd);
}
