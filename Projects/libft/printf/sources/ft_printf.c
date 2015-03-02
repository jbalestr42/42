/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:04:01 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:38:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int		is_valid_options(const char *s, int len, isvalid *is_valid)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (!is_valid(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_parse(t_opt *opts, va_list ap, const char *s, int *offset)
{
	int		i;

	*offset = 0;
	while (s[*offset])
	{
		i = 0;
		while (i < NB_OPT && opts[i].name != s[*offset])
			i++;
		if (i < NB_OPT && opts[i].name == s[*offset])
		{
			if (!is_valid_options(s, *offset, opts[i].is_valid))
			{
				ft_putchar(*s);
				*offset = 1;
				return (1);
			}
			*offset = *offset + 1;
			return (opts[i].parse_opt(ap, s, *offset));
		}
		*offset = *offset + 1;
	}
	*offset = 0;
	return (0);
}

static int		ft_printf_helper(const char *s, va_list ap)
{
	t_opt		opts[NB_OPT];
	int			count;
	int			offset;
	int			i;

	i = 0;
	count = 0;
	get_opts(opts);
	while (s[i])
	{
		while (s[i] == '%')
		{
			count += ft_parse(opts, ap, &s[++i], &offset);
			i += offset;
			if (!s[i])
				return (count);
		}
		ft_putchar(s[i]);
		count++;
		i++;
	}
	va_end(ap);
	return (count);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	int			count;

	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	va_start(ap, s);
	count = ft_printf_helper(s, ap);
	va_end(ap);
	return (count);
}
