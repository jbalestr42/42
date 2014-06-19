#include <stdio.h>
#include <termios.h>
#include <curses.h>
#include <term.h>
#include "./libft/includes/libft.h"

typedef struct  s_term_data
{
    unsigned int    max_length;
    int             uld_size;
    int             *uld;
    int             index;
    void            *p;
    char            **av;
    char            *term_name;
}               t_term_data;

int     tputs_putint(int c)
{
    write(1, &c, 1);
    return (EXIT_SUCCESS);
}

int     init_term(t_term_data data)
{
    struct termios  term;

    if (tcgetattr(0, &term) == -1)
        return (EXIT_FAILURE);
    if (!(data.term_name = getenv("TERM")))
    {
        ft_putstr("Specify a terminal type with `setenv TERM '.\n");
        exit(EXIT_FAILURE);
    }
    if (tgetent(NULL, data.term_name) == ERR)
        exit(EXIT_FAILURE);
    if (!isatty(0))
    {
        ft_putstr("A problem with the chosen file descriptor occured.\n");
        exit(EXIT_FAILURE);
    }
    term.c_lflag &= ~ICANON;
    term.c_lflag &= ~ECHO;
    term.c_lflag &= ~OPOST;
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSADRAIN, &term) == -1)
        return (-1);
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    char        buff[5] = {0};
    t_term_data data;

    init_term(data);
    while (!(buff[0] == 27 && buff[1] == 0 && buff[2] == 0))
    {
        ft_bzero(buff, 5);
        read(0, buff, 4);
        buff[4] = '\0';
        printf("%d %d %d %d\n", (int)buff[0], (int)buff[1], (int)buff[2], (int)buff[3]);
    }
    return (0);
}
