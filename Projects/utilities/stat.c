/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:56:57 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/13 03:07:50 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
/*#define MAJOR(dev)      ((dev)>>8)
#define MINOR(dev)      ((dev) & 0xff)
*/
#define MINORBITS       20
#define MINORMASK       ((1U << MINORBITS) - 1)

#define MAJOR(dev)      ((unsigned int) ((dev) >> (MINORBITS + 4)))
#define MINOR(dev)      ((unsigned int) ((dev) & MINORMASK))


typedef struct		s_list
{
	struct stat		*file_stat;
	struct s_list	*next;
}					t_list;

char	ft_file_type(struct stat *data)
{
	char	c;

	c = ' ';
	c = S_ISREG(data->st_mode) ? '-' : c;
	c = S_ISDIR(data->st_mode) ? 'd' : c;
	c = S_ISCHR(data->st_mode) ? 'c' : c;
	c = S_ISBLK(data->st_mode) ? 'b' : c;
	c = S_ISFIFO(data->st_mode) ? 'p' : c;
	c = S_ISLNK(data->st_mode) ? 'l' : c;
	c = S_ISSOCK(data->st_mode) ? 's' : c;
	return (c);
}

int main(int argc, char **argv)
{
	struct timespec		time;
	time_t				ctime;
	if (argc != 2)
		return (1);

	struct stat fileStat;
	if (lstat(argv[1],&fileStat) < 0)
		return (1);

	time = fileStat.st_mtimespec;

	printf("Information for %s\n",argv[1]);
	printf("---------------------------\n");
	printf("Device inode: \t\t%d\n",fileStat.st_dev);
	printf("File inode: \t\t%d\n",fileStat.st_ino);
	printf("File Size: \t\t%d bytes\n",fileStat.st_size);
	printf("Number of Links: \t%d\n",fileStat.st_nlink);
	printf("User-id: \t\t%d\n",fileStat.st_uid);
	printf("Group-id: \t\t%d\n",fileStat.st_gid);
	printf("Time last modif:\t%d\n",time.tv_sec);
	printf("Time last modif nsec:\t%ld\n",time.tv_nsec);
	printf("Blocks allocated for file:\t%d\n",fileStat.st_blocks);

	printf("File Permissions: \t");
	printf( "%c",  ft_file_type(&fileStat));
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");

	t_list	*node;
	printf("Size of struct node before malloc : %d bytes\n", sizeof(*node));
	node = (t_list *)malloc(sizeof(t_list));
	node->file_stat = &fileStat;
	node->next = NULL;
	printf("Size of struct node after malloc : %d bytes\n", sizeof(*node));
	printf("Size of file_stat : %d bytes\n", sizeof(fileStat));
	printf("Size of struct stat : %d bytes\n", sizeof(struct stat));
	printf("Size of struct t_list : %d bytes\n", sizeof(t_list));
	printf("Major minor: %i - %i\n", MAJOR(fileStat.st_rdev), MINOR(fileStat.st_rdev));
	free(node);
	return (0);
}
