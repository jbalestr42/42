/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 18:55:23 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 17:50:38 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_opt	get_opt(char c, parser *p, isvalid *v)
{
	t_opt	opt;

	opt.name = c;
	opt.parse_opt = p;
	opt.is_valid = v;
	return (opt);
}

void			get_opts(t_opt *opts)
{
	opts[0] = get_opt('s', &parse_str, &ft_isvalidstr);
	opts[1] = get_opt('i', &parse_nbr, &ft_isvalidnbr);
	opts[2] = get_opt('d', &parse_nbr, &ft_isvalidnbr);
	opts[3] = get_opt('c', &parse_char, &ft_isvalidstr);
	opts[4] = get_opt('u', &parse_unbr, &ft_isvalidunbr);
	opts[5] = get_opt('o', &parse_octal, &ft_isvalidunbr);
	opts[6] = get_opt('x', &parse_hexa, &ft_isvalidunbr);
	opts[7] = get_opt('X', &parse_hexaupper, &ft_isvalidunbr);
	opts[8] = get_opt('%', &parse_percent, &ft_isvalidstr);
	opts[9] = get_opt('p', &parse_addr, &ft_isvalidstr);
	opts[10] = get_opt('b', &parse_bin, &ft_isvalidstr);
	opts[11] = get_opt('Z', &parse_z, &ft_isvalidstr);
	opts[12] = get_opt('f', &parse_fnbr, &ft_isvalidfnbr);
}
