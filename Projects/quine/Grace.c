#include <stdio.h>
/*
    123
*/
#define P
#define W
#define FT(a)int main(){FILE *f = fopen("Grace_kid.c", "w+"); fprintf(f, a, #a);}
FT("#include <stdio.h>\n/*\n    123\n*/\n#define P\n#define W\n#define FT(a)int main(){FILE *f = fopen(\"Grace_kid.c\", \"w+\"); fprintf(f, a, #a);}\nFT(%s)\n")
