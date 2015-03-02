
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int			main(int argc, char **argv, char **env)
{
	printf("%s\n", argv[2]);
	execve(argv[1], &argv[1], env);
	return (0);
}
