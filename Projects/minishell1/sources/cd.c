/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:57:54 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/27 19:48:18 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static int		home(char **envp)
{
	int			ret;

	ret = 0;
	if (chdir(ft_getenv(envp, "HOME")))
		return (error(NSFOD, ft_getenv(envp, "HOME")));
	envp = ft_setenv(envp, "OLDPWD", ft_getenv(envp, "PWD"), 1);
	envp = ft_setenv(envp, "PWD", ft_getenv(envp, "HOME"), 1);
	return (ret);
}

static int		previous(char **envp)
{
	int			ret;
	char		*pwd;

	ret = 0;
	pwd = ft_strdup(ft_getenv(envp, "PWD"));
	if (chdir(ft_getenv(envp, "OLDPWD")) < 0)
		return (error(NSFOD, ft_getenv(envp, "OLDPWD")));
	envp = ft_setenv(envp, "PWD", ft_getenv(envp, "OLDPWD"), 1);
	envp = ft_setenv(envp, "OLDPWD", pwd, 1);
	ft_putendl(ft_getenv(envp, "PWD"));
	ft_strdel(&pwd);
	return (ret);
}

static int		path(char **envp, char *argv)
{
	int			ret;
	char		*pwd;
	char		*tmp;

	ret = 0;
	if (chdir(argv))
		return (error(NSFOD, argv));
	if (argv[0] == '/')
	{
		envp = ft_setenv(envp, "OLDPWD", ft_getenv(envp, "PWD"), 1);
		envp = ft_setenv(envp, "PWD", argv, 1);
	}
	else
	{
		tmp = ft_strjoin(ft_getenv(envp, "PWD"), "/");
		pwd = ft_strjoin(tmp, argv);
		envp = ft_setenv(envp, "OLDPWD", ft_getenv(envp, "PWD"), 1);
		envp = ft_setenv(envp, "PWD", pwd, 1);
		ft_strdel(&tmp);
		ft_strdel(&pwd);
	}
	return (ret);
}

void			parse_cd(char **argv, char **envp)
{
	int			argc;

	argc = count_split(argv);
	if (argc == 1)
		home(envp);
	else if (argc == 2 && !ft_strcmp(argv[1], "-") && !argv[2])
		previous(envp);
	else if (argc == 2 && argv[1][0] == '~' && !argv[2])
		ft_putendl("tild not implemented");
	else if (argc == 2)
		path(envp, argv[1]);
	else
		error(INVPTH, NULL);
}
