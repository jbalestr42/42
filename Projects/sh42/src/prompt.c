/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 19:22:36 by hjeannin          #+#    #+#             */
/*   Updated: 2014/05/25 19:24:31 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sh.h>
#include <libft.h>

void			ft_prompt(void)
{
	char		*post;

	ft_putstr("\033[034;1m{\033[31;1m");
	post = ft_getpost();
	ft_putstr(post);
	free(post);
	ft_putstr("\033[034;1m} -\033[0m ");
}
