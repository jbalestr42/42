/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:38:57 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 01:05:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

int main()
{
	int		i;

	for(i=0; i<sys_nerr; i++)
			        printf("sys_errlist[%d] = \"%s\"\n", i, sys_errlist[i]);
		    return 0;
}
