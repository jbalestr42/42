/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 22:04:43 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/21 22:04:44 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if ((sign = *str == '-' ? -1 : 1) == -1 || *str == '+')
		str++;
	while (*str && ft_isdigit(*str))
		result = (result * 10) + *str++ - '0';
	return (result * sign);
}
