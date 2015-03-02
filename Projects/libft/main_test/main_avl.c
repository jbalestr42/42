/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_avl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 12:42:33 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/11 19:21:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

typedef struct	s_test
{
	char		*s;
}				t_test;

int		ft_cmp(void *c1,  void *c2)
{
	t_test	*a1;
	t_test	*a2;

	a1 = (t_test *)c1;
	a2 = (t_test *)c2;
	return (ft_strcmp(a1->s, a2->s));
}

void	ft_del(void *content, size_t content_size)
{
	t_test		*tmp;

	tmp = (t_test *)content;
	ft_strdel(&tmp->s);
	ft_memdel(&content);
}

void	inorder(t_avl *tree)
{
	t_test	*s;

	if (tree == NULL)
		return ;
	else
	{
		s = (t_test *)tree->content;
		inorder(tree->left);
		printf("%s\n", s->s);
		inorder(tree->right);
	}
}

void	ft_print(t_avl *node)
{
	t_test	*t;

	t = (t_test *)node->content;
	ft_putendl(t->s);
}

int		main(void)
{
	char		*s[6] = { "bonjour", "banjour", "adieu", "bye", "prout", "bonjour" };
	t_avl		*head;
	t_avl		*tmp;
	t_test		*t;
	int			i;

	i = 0;
	head = NULL;
	while (i < 6)
	{
		ft_putendl("add new item");
		t = (t_test *)malloc(sizeof(t_test));
		t->s = ft_strdup(s[i++]);
		tmp = ft_avlnew(t, sizeof(t));
		head = ft_avladd(head, tmp, &ft_cmp);
	}
	ft_putendl("--------------------");
	ft_avliter_inorderrev(head, &ft_print);
	ft_putendl("--------------------");
	ft_avliter_inorder(head, &ft_print);
	ft_putendl("--------------------");
	ft_avldel(&head, &ft_del);
	inorder(head);
	ft_putendl("--------------------");
	return (0);
}
