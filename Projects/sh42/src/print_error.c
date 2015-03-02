/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:33:06 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/23 21:33:06 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int			ft_print_error(char *error)
{
	ft_putstr_fd("42sh: command not found:", 2);
	ft_putendl_fd(error, 2);
	return (0);
}
