/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 19:19:26 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/27 19:19:33 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"

static int		echo_back(int argc, char **argv, char **envp, int new_line)
{
	int			i;

	i = -1;
	(void)envp;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		if (i + 1 < argc)
			ft_putstr(" ");
	}
	if (!new_line)
		ft_putendl("");
	return (0);
}

static int		echo_no_back(int argc, char **argv, char **envp, int new_line)
{
	int			i;

	i = -1;
	(void)envp;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		if (i + 1 < argc)
			ft_putstr(" ");
	}
	if (!new_line)
		ft_putendl("");
	return (0);
}

static int		echo_all(int argc, char **argv, char **envp)
{
	int			i;
	int			new_line;
	int			back_slash;

	i = -1;
	new_line = 0;
	back_slash = 1;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'e')
				back_slash = 2;
			else if (argv[i][1] == 'E' && back_slash != 2)
				back_slash = 0;
			else if (argv[i][1] == 'n')
				new_line = 1;
		}
		else
			break ;
	}
	if (back_slash)
		return (echo_back(argc - i, &argv[i], envp, new_line));
	else
		return (echo_no_back(argc - i, &argv[i], envp, new_line));
}

static int		echo(int argc, char **argv, char **envp)
{
	if (argc == 1)
	{
		ft_putendl("");
		return (0);
	}
	else
		return (echo_all(argc - 1, &argv[1], envp));
}

void			parse_echo(char **argv, char **envp)
{
	echo(count_split(argv), argv, envp);
}
