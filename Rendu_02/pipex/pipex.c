/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:09:14 by jbalestr          #+#    #+#             */
/*   Updated: 2014/05/09 18:06:04 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **av, char **ae)
{
	int		pipefd[2];
	int		in_out[2];
	int		pid;

	if ((in_out[0] = open(av[1], O_RDONLY)) == -1)
		return ;
	if ((in_out[1] = open(av[4], O_CREAT | O_TRUNC | O_WRONLY,
			S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR)) == -1)
		return ;
	if ((pipe(pipefd)) == -1)
		return ;
	if ((pid = fork()) == -1)
		return ;
	if (pid == 0)
		ft_if_function(pipefd, in_out, av, ae);
	else
		ft_else_function(pipefd, in_out, av, ae);
}

void	ft_if_function(int pipefd[2], int in_out[2], char **av, char **ae)
{
	char		**newav;
	char		*result;

	result = NULL;
	if ((dup2(pipefd[0], 0)) == -1)
		return ;
	if ((dup2(in_out[1], 1)) == -1)
		return ;
	close(pipefd[1]);
	close(in_out[0]);
	if ((newav = ft_strsplit(av[3], ' ')) == NULL)
		return ;
	if (access(newav[0], X_OK | F_OK) == 0)
		result = ft_strcpycat(result, newav[0]);
	else
		result = search_exe(ae, newav[0]);
	if (!result || (ft_strcmp(result, "Not Found") == 0))
	{
		ft_putstr("pipex: command not found: ", 2, 0);
		ft_putstr(newav[0], 2, 1);
		return ;
	}
	execve(result, newav, ae);
}

void	ft_else_function(int pipefd[2], int in_out[2], char **av, char **ae)
{
	char		**newav;
	char		*result;

	result = NULL;
	if ((dup2(in_out[0], 0)) == -1)
		return ;
	if ((dup2(pipefd[1], 1)) == -1)
		return ;
	close(in_out[1]);
	close(pipefd[0]);
	if ((newav = ft_strsplit(av[2], ' ')) == NULL)
		return ;
	if (access(newav[0], X_OK | F_OK) == 0)
		result = ft_strcpycat(result, newav[0]);
	else
		result = search_exe(ae, newav[0]);
	if (!result || (ft_strcmp(result, "Not Found") == 0))
	{
		ft_putstr("pipex: command not found: ", 2, 0);
		ft_putstr(newav[0], 2, 1);
		return ;
	}
	execve(result, newav, ae);
}

char	*search_exe(char **ae, char *to_find)
{
	char	*str;
	char	**paths;
	char	*pwd;
	int		i;

	i = 0;
	paths = cut_path(ae);
	while (paths[i])
	{
		str = ft_strcpycat(ft_strcpycat(paths[i], "/"), to_find);
		if (access(str, X_OK | F_OK) == 0)
			return (str);
		free(str);
		i++;
	}
	pwd = ft_getpwd(ae);
	if (pwd)
	{
		str = ft_strcpycat(ft_strcpycat(pwd, "/"), to_find);
		if (access(str, X_OK | F_OK) == 0)
			return (str);
	}
	free(str);
	return ("Not Found");
}
