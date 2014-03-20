#include <stdlib.h>
#include "obj_file.h"

int					ft_strlen_tab(char **tab)
{
	int				len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

void				free_split(char **s)
{
	int				i;

	i = -1;
	while (s[++i])
		free(s[i]);
}

