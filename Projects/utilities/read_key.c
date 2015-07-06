#include <stdio.h>
#include <termios.h>
#include <string.h>

typedef struct  s_term_data
{
	unsigned int    max_length;
	int             uld_size;
	int             *uld;
	int             index;
	void            *p;
	char            **av;
	char            *term_name;
}				t_term_data;

int     init_term(t_term_data data)
{
	struct termios  term;

	if (tcgetattr(0, &term) == -1)
		return (0);
	term.c_lflag &= ~ICANON;
	term.c_lflag &= ~ECHO;
	term.c_lflag &= ~OPOST;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	return (0);
}

int main(int ac, char **av)
{
	char        buff[6] = {0};
	t_term_data data;
	int			j;

	init_term(data);
	while (!(buff[0] == 27 && buff[1] == 0 && buff[2] == 0))
	{
		bzero(buff, 6);
		read(0, buff, 6);
		for (j = 0; j < 6; j++)
			printf("%x\n", buff[j]);
	}
	return (0);
}
