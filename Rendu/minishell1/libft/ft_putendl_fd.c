/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 00:32:50 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/26 00:32:51 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
