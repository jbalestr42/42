#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
(void)argv;
int i = 5;
char *n;
char *nn;
if (argc != 1)i--;
asprintf(&n, "Sully_%i", i);
asprintf(&nn, "%s.c", n);
FILE *f = fopen(nn, "w+");
char *c = "#include <stdio.h>%c#include <stdlib.h>%cint main(int argc, char **argv)%c{%c(void)argv;%cint i = %i;%cchar *n;%cchar *nn;%cif (argc != 1)i--;%casprintf(&n, %cSully_%ci%c, i);%casprintf(&nn, %c%cs.c%c, n);%cFILE *f = fopen(nn, %cw+%c);%cchar *c = %c%s%c;%cfprintf(f, c, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 34, 10, 34, c, 34, 10, 10, 10, 10, 34, 37, 37, 37, 34, 10, 10, 34, 37, 37, 34, 10, 10, 10);%cfclose(f);%cchar *s;%cif (i > 0){asprintf(&s, %cclang -Wall -Wextra -Werror %cs -o %cs; ./%cs 1%c, nn, n, n);%c	system(s);}%celse if (i == 0){asprintf(&s, %cclang -Wall -Wextra -Werror %cs -o %cs%c, nn, n);%c	system(s);}%c}%c";
fprintf(f, c, 10, 10, 10, 10, 10, i, 10, 10, 10, 10, 34, 37, 34, 10, 34, 37, 34, 10, 34, 34, 10, 34, c, 34, 10, 10, 10, 10, 34, 37, 37, 37, 34, 10, 10, 34, 37, 37, 34, 10, 10, 10);
fclose(f);
char *s;
if (i > 0){asprintf(&s, "clang -Wall -Wextra -Werror %s -o %s; ./%s 1", nn, n, n);
	system(s);}
else if (i == 0){asprintf(&s, "clang -Wall -Wextra -Werror %s -o %s", nn, n);
	system(s);}
}
