/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 17:18:41 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 17:18:48 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_get_file_size(char *bloc, int *i)
{
	int				file_size;

	file_size = 0;
	while (bloc[*i] != ' ' && bloc[*i] != '\t')
	{
		file_size++;
		(*i)++;
	}
	if (bloc[(*i) - 1] == ' ' || bloc[(*i) - 1] == '\t')
		file_size--;
	return (file_size);
}
