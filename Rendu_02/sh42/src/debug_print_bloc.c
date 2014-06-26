/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_bloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:57:24 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/26 12:57:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh.h>

void					ft_debug_print_bloc(t_bloc *bloc)
{
	ft_putstr_fd("bloc:\n", 2);
	ft_putstr_fd("was_redir : ", 2);
	ft_putnbr_fd(bloc->was_redir, 2);
	ft_putstr_fd("\nredir     : ", 2);
	ft_putnbr_fd(bloc->redir, 2);
	ft_putstr_fd("\nfd        : ", 2);
	ft_putnbr_fd(bloc->fd, 2);
	ft_putstr_fd("\ntcmd      :\n", 2);
	ft_print_array(bloc->tcmd);
	ft_putstr_fd("cmd       : ", 2);
	ft_putstr_fd(bloc->cmd, 2);
	ft_putstr_fd("\nsep_prev  : ", 2);
	ft_putnbr_fd(bloc->sep_prev, 2);
	ft_putstr_fd("\nsep_next  : ", 2);
	ft_putnbr_fd(bloc->sep_next, 2);
	ft_putstr_fd("\nsuccess   : ", 2);
	ft_putnbr_fd(bloc->success, 2);
	ft_putstr_fd("\ncmd_type    : ", 2);
	ft_putnbr_fd(bloc->cmd_type, 2);
	ft_putchar_fd('\n', 2);
}
