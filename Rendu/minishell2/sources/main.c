/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 11:59:51 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 16:57:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "ft_minishell2.h"

int				main(int argc, char **argv, char **envp)
{
		(void)argv;
	if (argc != 1)
		return (error(ARGC, NULL));
	if (!envp[0])
		return (error(NOENV, NULL));
	// Il faudra changer cet fonction et l'ajouter dans le prompt
	prompt(envp);
	return (0);
}
