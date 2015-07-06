/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:20:30 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 22:54:11 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh.h>

static int		ft_count_space(char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

static char		*ft_rm_space(char *str)
{
	int			i;
	int			j;
	char		*new;

	i = 0;
	j = 0;
	new = NULL;
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str)
								- ft_count_space(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			new[j] = str[i];
			i++;
			j++;
		}
		else
			i++;
	}
	new[j] = '\0';
	return (new);
}

static void		ft_set_zero(int *pipe, int *and, int *semicolon)
{
	*pipe = 0;
	*and = 0;
	*semicolon = 0;
}

static int		ft_check_error(char *str)
{
	int			i;
	int			pipe;
	int			and;
	int			semicolon;

	i = 0;
	ft_set_zero(&pipe, &and, &semicolon);
	while (str[i] != '\0')
	{
		if (str[i] == '|' && str[i + 1] == '|')
			pipe++;
		if (str[i] == '&' && str[i + 1] == '&')
			and++;
		if (str[i] == ';' && str[i + 1] == ';')
			semicolon++;
		if (str[i] != '|' && str[i] != ';' && str[i] != '&')
			ft_set_zero(&pipe, &and, &semicolon);
		if (pipe >= 2 || and >= 2 || semicolon >= 1)
			return (0);
		i++;
	}
	return (1);
}

int				ft_entry_error(char *str)
{
	char		*new;

	new = ft_rm_space(str);
	if (!ft_check_error(new))
	{
		ft_print_parse_error("Too many separators");
		free(new);
		free(str);
		return (0);
	}
	free(new);
	return (1);
}
