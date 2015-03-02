/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:49:20 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/05 18:59:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_lstsize(t_list *begin);
void	ft_lstrev(t_list **begin);
t_list	*lst_remove(t_list *begin, int fd);

typedef struct	s_buff
{
	char		buf[BUFF_SIZE];
	int			read;
	int			index;
	int			fd;
}				t_buff;

int		lst_cmp(t_buff *content, int fd)
{
	if (content->fd == fd)
		return (1);
	return (0);
}

void	ft_print_list(t_list **begin)
{
	t_list	*elem;

	elem = *begin;
	if (elem != NULL)
	{
		while (elem != NULL)
		{
			printf( "%s\n", (char*)elem->content);
			elem = elem->next;
		}
	}
}

int		main(void)
{
	t_list	*begin;

	begin = NULL;
	printf("------ lstsize ------\n");
	printf("Empty list : %i\n", ft_lstsize(begin));
	ft_lstpushback(&begin, ft_lstnew("first", sizeof("first")));
	printf("One elem : %i\n", ft_lstsize(begin));
	ft_lstpushback(&begin, ft_lstnew("second", sizeof("second")));
	printf("Two elem : %i\n", ft_lstsize(begin));
	ft_lstpushback(&begin, ft_lstnew("third", sizeof("third")));
	printf("Three elem : %i\n", ft_lstsize(begin));
	printf("------ lstrev ------\n");
	printf("~~ before\n");
	ft_print_list(&begin);
	ft_lstrev(&begin);
	printf("~~ after\n");
	ft_print_list(&begin);
}
