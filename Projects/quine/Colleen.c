#include <stdio.h>
/*
    123
*/
void p(char *s){printf(s, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10);}
int main()
{
/*
    456
*/
p("#include <stdio.h>%c/*%c    123%c*/%cvoid p(char *s){printf(s, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 34, s, 34, 10, 10);}%cint main()%c{%c/*%c    456%c*/%cp(%c%s%c);%c}%c");
}
