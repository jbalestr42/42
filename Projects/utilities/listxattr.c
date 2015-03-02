/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listxattr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 06:12:59 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/12 06:30:46 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/xattr.h>
#include <stdlib.h>

int		main(void)
{
	char	*buf;

	buf = (char *)malloc(500);
	getxattr("~/Documents", "", (void *)buf, 500, 0, XATTR_SHOWCOMPRESSION);
	buf[499] = '\0';
	printf("%s\n", buf);
}
