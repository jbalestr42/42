/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/27 21:31:30 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 22:36:06 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <sh.h>
#include <libft.h>

int						ft_find_cmd(char *line, t_list *envi)
{
	int			e;
	int			b;
	char		**array;

	e = -1;
	b = -1;
	if (line[0] != '\0')
	{
		array = ft_str_to_tab(line);
		e = ft_check_execve(array, envi);
		b = ft_check_built_in(array);
		ft_free_array(array);
		if (e == 1 && b == 0)
			return (EXEC);
		if (b == 1)
			return (BLTI);
		if (e == 0 && b == 0)
			return (0);
	}
	return (1);
}

int						ft_check_cmds(t_list *cmds, t_list *envi)
{
	t_elem				*elem;

	elem = cmds->begin;
	while (elem)
	{
		elem->bloc->cmd_type = ft_find_cmd(elem->bloc->cmd, envi);
		elem = elem->next;
	}
	return (1);
}

int						ft_check_sep(char *line, int i)
{
	if (line[i] == ';')
		return (SEMICOLON);
	else if (line[i] == '|' && line[i + 1] == '|')
		return (OR);
	else if (line[i] == '|' && line[i + 1] != '|')
	{
		if (i > 0 && line[i - 1] == '|')
			return (-1);
		return (PIPE);
	}
	else if (line[i] == '&' && line[i + 1] == '&')
		return (AND);
	return (-1);
}

int						ft_parse_line(char *old, t_list *cmds)
{
	int					i;
	char				*line;
	char				*new_bloc;

	line = NULL;
	if (!(line = ft_clean_line(old)))
		return (0);
	if (!(ft_entry_error(line)))
		return (0);
	i = 0;
	while (line[i])
	{
		new_bloc = ft_get_bloc(line, &i);
		if (!ft_fill_bloc(cmds, new_bloc))
			return (0);
		free(new_bloc);
	}
	free(line);
	return (1);
}

int						ft_parse(char *line, t_data *data)
{
	if (!(data->cmds = ft_list_new()))
		return (0);
	if (line[0] != '\0')
		ft_parse_line(line, data->cmds);
	if (ft_check_parse_error(data->cmds))
		ft_check_cmds(data->cmds, data->envi);
	else
		return (-1);
	return (1);
}
