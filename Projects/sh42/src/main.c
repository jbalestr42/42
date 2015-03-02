/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 18:11:03 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/26 15:07:46 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <libft.h>
#include <stdlib.h>

int	g_sep_size[SEP_MAX] =
{
	SEMICOLON_SIZE,
	PIPE_SIZE,
	AND_SIZE,
	OR_SIZE
};

int				main(int argc, char **argv, char **environ)
{
	(void)argc;
	(void)argv;
	if (!(g_data = (t_data *)malloc(sizeof(t_data))))
		return (1);
	if (*environ == NULL)
	{
		ft_putstr("Env is empty\n");
		return (0);
	}
	if (!(g_data->envi = ft_list_new()))
		return (1);
	if (!ft_init_data(g_data->envi, environ))
		return (1);
	if (!init(g_data))
		return (1);
	if (!ft_shell_init(g_data))
		return (1);
	reset_term(&g_data->term);
	free(g_data);
	return (0);
}
