#include "lemin.h"
#include "gnl.h"
#include <stdio.h>

int			read_ant_nb(void)
{
	char	*line;
	int		nb;

	line = NULL;
	nb = -1;
	while (get_next_line(STD_IN, &line))
	{
		if (line)
		{
			if (line[0] == '#')
				continue ;
			nb = ft_atoi(line);
			//printf("%s\n", line);
			break ;
		}
	}
	return (nb);
}

void		read_room(char *line)
{
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	if (tmp && ft_strlen_tab(tmp) == 3)
	{
		
	}
	else
		return (-1); // no more room
}

int			read_nodes(void)
{
	char	**tmp;
	char	*line;
	int		nb;
	int		start;

	line = NULL;
	nb = -1;
	start = 0;
	while (get_next_line(STD_IN, &line))
	{
		if (line)
		{
			if (line[0] == '#')
			{
				if (ft_strequ("##start", line))
				{
					printf("found start\n");
					start += 1;
					if (start > 3)
						break ;
				}
				if (ft_strequ("##end", line))
				{
					printf("found end\n");
					start += 2;
					if (start > 3)
						break ;
				}
			}
			tmp = ft_strsplit(line, ' ');
			if (tmp && ft_strlen_tab(tmp) == 3)
				read_room(tmp);
			else
				break ;
		}
	}
	if (start != 3)
		printf("ERROR, start or end is wrong\n");
	return (nb);
}

int main(void)
{
	int nb = read_ant_nb();
	if (nb <= 0)
		printf("ERROR, wrong ants number\n");
	read_nodes();
	return (0);
}
