/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 08:03:15 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/08 20:55:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int		main (int argc, char **argv)
{
	DIR *dp;
	struct dirent *ep;

	dp = opendir (argv[1]);
	if (dp != NULL)
	{
		while (ep = readdir (dp))
			puts (ep->d_name);
		(void) closedir (dp);
	}
	else
		perror ("Couldn't open the directory");
	return 0;
}
