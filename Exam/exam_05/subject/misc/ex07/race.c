#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char secret[]	= ""; //Vous pensez quand meme pas qu'on va vous le donner
char path_tmp[]	= "/tmp/asiat_racer";

void	scrub(char *s)
{
	//On va quand meme pas vous filer ca non plus
}

int main(void)
{
	int fd_tmp;
	int fd_random;
	int rand;
	int entered_value;

	fd_random = open("/dev/random", O_RDONLY);
	read(fd_random, &rand, sizeof(rand));
	close(fd_random);

	mktemp(path_tmp);
	chmod(path_tmp, 0644);

	fd_tmp = open(path_tmp, O_RDWR | O_CREAT | O_TRUNC);
	write(fd_tmp, &rand, sizeof(rand));
	close(fd_tmp);
	usleep(10000);
	unlink(path_tmp);

	printf("Please give me a value: ");
	scanf("%d", &entered_value);
	if (entered_value == rand)
	{
		scrub(secret);
		printf("The secret is: \"%s\"\n", secret);	
	}
	else
		printf("You failed !\n");
	return (0);
}
