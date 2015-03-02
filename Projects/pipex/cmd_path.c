/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:02:43 by jbalestr          #+#    #+#             */
/*   Updated: 2014/05/09 18:05:24 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**cut_path(char **ae)
{
	int		i;
	char	*path;

	i = 0;
	while (ae[i] && ft_strncmp(ae[i], "PATH=", 5) != 0)
		i++;
	if ((path = malloc(sizeof(char) * ft_strlen(ae[i]) + 1)) == NULL)
		return (NULL);
	if (ae[i])
		path = ft_strcpy(path, ae[i] + 5);
	if (path)
		return (ft_strsplit(path, ':'));
	return (NULL);
}

char	*ft_getpwd(char **ae)
{
	int		i;
	char	*pwd;

	pwd = NULL;
	i = 0;
	while (ae[i] && ft_strncmp(ae[i], "PWD=", 4) != 0)
		i++;
	if (ae[i])
	{
		if ((pwd = malloc(sizeof(char) * ft_strlen(ae[i]) + 1)) == NULL)
			return (NULL);
		pwd = ft_strcpy(pwd, ae[i] + 4);
	}
	return (pwd);
}
