/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbropt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 17:01:53 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 17:39:20 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_nbropt(const char *s, int len, int *i, char *tab)
{
	while (*i < len && (!ft_isdigit(s[*i]) || s[*i] == '0'))
	{
		if (s[*i] == ' ' && tab[0] == ' ')
			tab[2] = ' ';
		else if (s[*i] == '0')
			tab[1] = '0';
		else if (s[*i] == '+')
			tab[2] = '+';
		else if (s[*i] == '-')
		{
			if (tab[2] == ' ')
				tab[2] = '-';
			tab[0] = '-';
		}
		*i = *i + 1;
	}
}

static int		ft_display_nbropt(const char *s, char *tab, int nb, int nbr)
{
	int		total;

	if (!(total = 0) && *s == ' ' && tab[0] != '+')
	{
		total = ft_putchar(' ');
		if (nb < 0)
			nb--;
	}
	if (tab[2] != 'n')
		nb--;
	nb = nb < 0 ? 0 : nb;
	if (tab[0] == '-')
	{
		if (tab[2] == '+')
			total += ft_putchar(tab[2]);
		total += ft_putnbr(nbr);
	}
	total += ft_putnchar(tab[1], nb);
	if (tab[0] != '-')
	{
		if (tab[2] == '+')
			total += ft_putchar(tab[2]);
		total += ft_putnbr(nbr);
	}
	return (total);
}

int				ft_putnbropt(const char *s, int len, int nbr)
{
	char	opt[] = "  n";
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	get_nbropt(s, len, &i, opt);
	while (i < len && ft_isdigit(s[i]))
		nb = nb * 10 + s[i++] - '0';
	nb = nb - ft_intlen(nbr);
	return (ft_display_nbropt(s, opt, nb, nbr));
}
