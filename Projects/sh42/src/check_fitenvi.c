/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fitenvi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:00:29 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:00:30 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <sh.h>

int					ft_check_fitenvi(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			return (0);
		if (str[i] == '=' && str[i + 1] != '\0')
			return (1);
		i++;
	}
	return (0);
}
