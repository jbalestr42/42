/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 19:14:35 by rdavid            #+#    #+#             */
/*   Updated: 2014/05/21 20:28:51 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "sh.h"

inline static int		ft_check_echo_n(char *arg)
{
	const int			size = ft_strlen(arg);
	int					i;

	i = 1;
	while (i < size)
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

inline static void		ft_print_echo_args(char **c, int i)
{
	while (c[i] != NULL)
	{
		ft_putstr(c[i]);
		if (c[i + 1] != NULL)
			ft_putchar(' ');
		i++;
	}
}

int						ft_echo(char **c, t_list *envi)
{
	int					i;

	(void)envi;
	if (!c[1])
		return (write(1, "\n", 1));
	if (!ft_strncmp(c[1], "-n", 2) && ft_check_echo_n(c[1]))
	{
		i = 2;
		ft_print_echo_args(c, i);
		ft_putstr("\033[37;7m%\033[0m");
	}
	else
	{
		i = 1;
		ft_print_echo_args(c, i);
	}
	ft_putchar('\n');
	return (1);
}
