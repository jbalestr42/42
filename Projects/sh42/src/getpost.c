/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/23 22:13:08 by hjeannin          #+#    #+#             */
/*   Updated: 2014/05/23 22:26:51 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>

char			*ft_getpost(void)
{
	char		*res;
	char		c;
	int			fd;
	int			i;

	i = 0;
	if (!(fd = open("/etc/salt/minion_id", O_RDONLY)))
	{
		ft_putstr("Can't find post\n");
		exit(-1);
	}
	if (!(res = ft_memalloc(32)))
		exit(-1);
	while (read(fd, &c, 1))
	{
		if (c == '.')
			break ;
		res[i++] = c;
	}
	close(fd);
	res[i] = '\0';
	return (res);
}
