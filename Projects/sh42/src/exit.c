/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 23:55:32 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/26 15:06:52 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sh.h>
#include <libft.h>

int						ft_exit(char **cmd, t_list *envi)
{
	(void)cmd;
	(void)envi;
	ft_putendl_fd("\033[32mexit\033[0m", 2);
	reset_term(&g_data->term);
	exit(0);
}
