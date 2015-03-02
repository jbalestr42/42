/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:59:57 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/27 20:37:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

static char		*search_dir(char *path, char *name)
{
	DIR			*dirp;
	t_dirent	dirent;

	dirp = opendir(path);
	while ((dirent = readdir(dirp)))
	{
		if (!ft_strcmp(name, dirent->d_name))
		{
			path = ft_strjoin(path, "/");
			path = ft_strrealloc(path, ft_strlen(path) + ft_strlen(name));
			ft_strcat(path, name);
			closedir(dirp);
			return (path);
		}
	}
	closedir(dirp);
	return (NULL);
}

char			*find_path(char *name, char **envp)
{
	char		*path;
	char		**path_list;
	int			index;

	if (name[0] == '/' || (name[0] == '.' && name[1] && name[1] == '/'))
		return (name);
	path_list = ft_strsplit(ft_getenv(envp, "PATH"), ':');
	index = 0;
	path = NULL;
	while (path_list[index])
	{
		if ((path = search_dir(path_list[index], name)))
			break ;
		index++;
	}
	free_split(path_list);
	return (path);
}

static void		fork_handle(char **argv, char **envp)
{
	pid_t		pid;

	pid = fork();
	if (pid == 0)
	{
		execve(find_path(argv[0], envp), argv, envp);
		error(BADCMD, argv[0]);
		free_split(argv);
		error(EXIT, NULL);
	}
	else if (pid < 0 || waitpid(pid, NULL, 0) != pid)
	{
		free_split(argv);
		error(FORK_FAIL, NULL);
	}
	free_split(argv);
}

static void		execute(char *command, char **envp, t_builtin *builtins)
{
	char		**argv;
	int			i;

	i = 0;
	while (command[i] == ' ' || command[i] == '\t')
		i++;
	if (command[i])
	{
		argv = ft_strsplit(&command[i], ' ');
		ft_strdel(&command);
		if (!ft_strstr(BUILTIN, argv[0]))
			fork_handle(argv, envp);
		else
			builtin(argv, envp, builtins);
	}
}

int				prompt(char **envp)
{
	char		*line;
	t_builtin	builtins[NB_BUILTIN];

	get_builtins(builtins);
	ft_putstr(PROMPT);
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (line && *line)
			execute(line, envp, builtins);
		ft_putstr(PROMPT);
	}
	return (1);
}
