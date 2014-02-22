/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 15:03:25 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/31 01:39:22 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"

int		main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		return (error(ARGC, NULL));
	if (!envp[0])
		return (error(NOENV, NULL));
	prompt(envp);
	(void)argv;
	return (0);
}
