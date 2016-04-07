#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
/*
    123
*/
#define P
#define W(f,c,n) write(f,c,n)
#define T(a) int main(){int fd = open("Grace_kid.c", O_WRONLY | O_CREAT); char c[493]; sprintf(c, a, #a); W(fd, c, 492);}
T("#include <fcntl.h>\n#include <unistd.h>\n#include <stdio.h>\n/*\n    123\n*/\n#define P\n#define W(f,c,n) write(f,c,n)\n#define T(a) int main(){int fd = open(\"Grace_kid.c\", O_WRONLY | O_CREAT); char c[493]; sprintf(c, a, #a); W(fd, c, 492);}\nT(%s)\n")
