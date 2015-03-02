/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 17:05:12 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 17:32:39 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>

# define NB_OPT		13

typedef int		(parser)(va_list, const char *, int);
typedef int		(isvalid)(char c);

typedef struct	s_opt
{
	char		name;
	parser		*parse_opt;
	isvalid		*is_valid;
}				t_opt;

/*
** Helpers
*/
int		ft_isvalidnbr(char c);
int		ft_isvalidunbr(char c);
int		ft_isvalidfnbr(char c);
int		ft_isvalidstr(char c);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
int		ft_intlen(int nb);
void	ft_putstr(const char *s);
int		ft_putchar(char c);
int		ft_putnchar(char c, int n);
int		ft_putnbr(int nb);
int		ft_putunbr(unsigned int n);
int		ft_putfnbr(double n, int prec);
int		ft_putoctal(unsigned int n);
int		ft_puthexa(unsigned int n);
int		ft_puthexaupper(unsigned int n);
int		ft_putaddr(long unsigned int p);
int		ft_putbin(unsigned int p);
int		ft_putnbropt(const char *s, int len, int nbr);

/*
** Manage options
*/
void	get_opts(t_opt *opts);
int		ft_uint_to_base(unsigned int n, int base);
int		ft_uint_to_base_upper(unsigned int n, int base);
int		ft_luint_to_base(long unsigned int n, int base);
int		ft_luint_to_base_upper(long unsigned int n, int base);
int		parse_str(va_list ap, const char *s, int offset);
int		parse_char(va_list ap, const char *s, int offset);
int		parse_nbr(va_list ap, const char *s, int offset);
int		parse_unbr(va_list ap, const char *s, int offset);
int		parse_fnbr(va_list ap, const char *s, int offset);
int		parse_octal(va_list ap, const char *s, int offset);
int		parse_hexa(va_list ap, const char *s, int offset);
int		parse_hexaupper(va_list ap, const char *s, int offset);
int		parse_percent(va_list ap, const char *s, int offset);
int		parse_addr(va_list ap, const char *s, int offset);
int		parse_bin(va_list ap, const char *s, int offset);
int		parse_z(va_list ap, const char *s, int offset);

/*
** Main functions
*/
int		ft_parse_option(const char *s, int offset, int nbr);
int		ft_printf(const char *s, ...);

#endif /* !PRINTF_H */
