/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 13:57:17 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/29 17:59:50 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>
#include <unistd.h>

void	error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

t_lst	*sort(t_lst *l_a)
{
	t_lst	*l_b;
	int		cnt;
	int		max;

	l_b = NULL;
	max = 0;
	while (l_a)
	{
		cnt = 0;
		while (l_b && l_a->val < l_b->val && cnt < max)
		{
			rotate_b(&l_b);
			cnt++;
		}
		pswap_b(&l_a, &l_b);
		while (cnt-- > 0)
			rrotate_b(&l_b);
		max++;
	}
	while (l_b)
		pswap_a(&l_a, &l_b);
	return (l_a);
}

int		main(int argc, char **argv)
{
	t_lst	*a;

	a = NULL;
	if (argc < 2)
		error();
	while (argc > 1)
		lst_pushfront(&a, lst_new(ft_atoi(argv[--argc])));
	a = sort(a);
	write(1, "\b\n", 2);
	lst_del(a);
	return (0);
}
