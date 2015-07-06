/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 18:59:19 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/02 19:01:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t		ft_strlen(const char *s)
{
	const char		*c;
	const int		*word;
	unsigned int	word_text;

	if (!s)
		return (0);
	word = (int * )s;
	while (1)
	{
		word_text = *word;
		if ((word_text - 0x01010101) & ~word_text & 0x80808080)
		{
			c = (const char *)word;
			while (*c)
				c++;
			return (c - s);
		}
		word++;
	}
}
