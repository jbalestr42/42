/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/20 15:53:25 by exam              #+#    #+#             */
/*   Updated: 2014/02/20 18:24:00 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
				return (-1);
			return (1);
		}
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

int			get_value(char c1, char c2, int ret, char *c)
{
	char	tmp;

	tmp = c1 + c2 - '0' + ret;
	ret = 0;
	if (tmp > '9')
	{
		tmp = tmp - 10;
		ret = 1;
	}
	*c = tmp;
	return (ret);
}

void		rec_add(char *s1, char *s2, int len1, int len2, int ret)
{
	char	tmp;
	int		r;

	if (len1 >= 0 && len2 >= 0)
	{
		r = get_value(s1[len1], s2[len2], ret, &tmp);
		rec_add(s1, s2, --len1, --len2, r);
	}
	else if (len1 >= 0)
	{
		r = get_value(s1[len1], '0', ret, &tmp);
		rec_add(s1, s2, --len1, --len2, r);
	}
	else if (len2 >= 0)
	{
		r = get_value('0', s2[len2], ret, &tmp);
		rec_add(s1, s2, --len1, --len2, r);
	}
	else
	{
		if (ret)
			write(1, "1", 1);
		return ;
	}
	write(1, &tmp, 1);
}

int			get_sub_value(char c1, char c2, int ret, char *c)
{
	char	tmp;

	tmp = c1 - c2 - ret;
	if (tmp < 0)
	{
		tmp = tmp + 10;
		ret = 1;
	}
	else
		ret = 0;
	*c = tmp;
	return (ret);
}

void		rec_sub(char *s1, char *s2, int len1, int len2, int ret, int first)
{
	char	tmp;

	if (len1 >= 0 && len2 >= 0)
	{
		ret = get_sub_value(s1[len1], s2[len2], ret, &tmp);
		if (len1 == 0 && len2 == 0 && tmp == 0)
			first = 1;
		else
			first = 0;
		rec_sub(s1, s2, --len1, --len2, ret, first);
	}
	else if (len1 >= 0)
	{
		ret = get_sub_value(s1[len1], '0', ret, &tmp);
		if (len1 == 0 && tmp == 0)
			first = 1;
		else
			first = 0;
		rec_sub(s1, s2, --len1, --len2, ret, first);
	}
	else if (len2 >= 0)
	{
		ret = get_sub_value('0', s2[len2], ret, &tmp);
		if (len2 == 0 && tmp == 0)
			first = 1;
		else
			first = 0;
		rec_sub(s1, s2, --len1, --len2, ret, first);
	}
	else
		return ;
	if (first)
		return ;
	tmp += '0';
	write(1, &tmp, 1);
}

void		infin_add(char *s1, char *s2)
{
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return ;
	len1 = ft_strlen(s1) - 1;
	len2 = ft_strlen(s2) - 1;
	if (s1[0] == '-' && s2[0] == '-')
	{
		write(1, "-", 1);
		rec_add(&s1[1], &s2[1], len1 - 1, len2 - 1, 0);
	}
	else if (s1[0] == '-')
	{
		if (len1 - 1 > len2 || (len1 - 1 == len2 && ft_strcmp(s1, &s2[1]) < 0))
		{
			write(1, "-", 1);
			rec_sub(&s1[1], s2, len1 - 1, len2, 0, 1);
		}
		else
			rec_sub(s2, &s1[1], len2, len1 - 1, 0, 1);
	}
	else if (s2[0] == '-')
	{
		if (len2 - 1 > len1 || (len2 - 1 == len1 && ft_strcmp(&s2[1], s1) < 0))
		{
			write(1, "-", 1);
			rec_sub(&s2[1], s1, len2 - 1, len1, 0, 1);
		}
		else
			rec_sub(s1, &s2[1], len1, len2 - 1, 0, 1);
	}
	else
		rec_add(s1, s2, len1, len2, 0);
}

int			main(int argc, char **argv)
{
	if (argc == 3)
		infin_add(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
