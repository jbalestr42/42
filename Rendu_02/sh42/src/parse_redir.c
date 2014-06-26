/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 20:00:44 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/20 21:48:33 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <sh.h>

int					ft_parse_redir_1(t_bloc *bloc)
{
	int				i;
	char			*cmd;
	char			*file;
	int				j;

	i = 0;
	cmd = NULL;
	file = NULL;
	if (!(cmd = ft_copy_cmd(bloc->cmd, cmd, 0, ft_get_cmd_size(bloc->cmd, &i))))
		return (0);
	j = i;
	if (!(file = ft_copy_file(bloc->cmd, file, j,
							ft_get_file_size(bloc->cmd, &i))))
		return (0);
	free(bloc->cmd);
	bloc->cmd = cmd;
	if (!ft_open_redir(bloc, file))
	{
		free(file);
		return (0);
	}
	free(file);
	return (1);
}

static int			ft_gfs2(char *bloc, int *i)
{
	int				file_size;

	file_size = 0;
	if (bloc[*i] == ' ' || bloc[*i] == '\t')
		(*i)++;
	while (bloc[*i] != ' ' && bloc[*i] != '\t')
	{
		file_size++;
		(*i)++;
	}
	(*i)++;
	return (file_size);
}

static int			ft_gcs2(char *bloc, int *i)
{
	int				cmd_size;

	cmd_size = 0;
	while (bloc[*i])
	{
		cmd_size++;
		(*i)++;
	}
	return (cmd_size);
}

int					ft_parse_redir_2(t_bloc *bloc, int space)
{
	int				i;
	char			*cmd;
	char			*file;
	int				j;

	i = space + 1;
	cmd = NULL;
	file = NULL;
	if (bloc->cmd[i] == ' ' || bloc->cmd[i] == '\t')
		i++;
	j = i;
	if (!(file = ft_copy_file(bloc->cmd, file, j, ft_gfs2(bloc->cmd, &i))))
		return (0);
	j = i;
	if (!(cmd = ft_copy_cmd(bloc->cmd, cmd, j, ft_gcs2(bloc->cmd, &i))))
		return (0);
	free(bloc->cmd);
	bloc->cmd = cmd;
	if (!ft_open_redir(bloc, file))
	{
		free(file);
		return (0);
	}
	free(file);
	return (1);
}

int					ft_parse_redir_type(t_bloc *bloc, t_data *data)
{
	int				space;

	(void)data;
	space = bloc->cmd[0] == ' ' || bloc->cmd[0] == '\t';
	if ((space && bloc->cmd[1] == '<') || bloc->cmd[0] == '<')
	{
		if (!ft_parse_redir_2(bloc, space))
			return (0);
	}
	else
	{
		if (!ft_parse_redir_1(bloc))
			return (0);
	}
	return (1);
}
