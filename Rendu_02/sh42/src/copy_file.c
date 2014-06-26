/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/15 20:08:45 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/15 20:25:24 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char				*ft_copy_file(char *bloc, char *file, int i, int file_size)
{
	int				k;
	int				j;

	if (!(file = (char *)malloc(sizeof(char) * file_size + 1)))
	{
		perror("ft_copy_file()");
		return (NULL);
	}
	j = 0;
	k = i;
	while (i < k + file_size)
	{
		file[j] = bloc[i];
		j++;
		i++;
	}
	file[file_size] = '\0';
	return (file);
}
