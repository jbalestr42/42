/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 20:16:21 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/23 20:16:22 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <libft.h>

char					*ft_check_exist(char *str)
{
	if (access(str, F_OK) == 0)
		return (str);
	else
	{
		if (str[0] != '<')
		{
			ft_putstr_fd("42sh: ", 2);
			perror(str);
		}
	}
	return (NULL);
}
