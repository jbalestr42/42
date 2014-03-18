/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 12:00:51 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 16:41:19 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>
# include <unistd.h>
# include <string.h>
# include <libft.h>
# include <stdlib.h>

# define NB_BUILTIN	6
# define PROMPT		"$> "
# define BUILTIN	"cd env setenv unsetenv exit echo"

/* Error codes */
# define NB_ERR		8
# define ARGC		0
# define BADCMD		1
# define NSFOD		2
# define INVPTH		3
# define NOENV		4
# define BADVAL		5
# define FORK_FAIL	6
# define EXIT		7
# define PARSE_ERR	8

typedef void	(parser)(char **, char **);

typedef struct	s_builtin
{
	char		*name;
	parser		*builtin;
}				t_builtin;

typedef struct	s_error
{
	int			exit;
	char		*err_str;
}				t_error;

typedef struct dirent	*t_dirent;

/*
** Builtins
*/
void	get_builtins(t_builtin *builtins);
void	parse_cd(char **argv, char **envp);
void	parse_env(char **argv, char **envp);
void	parse_setenv(char **argv, char **envp);
void	parse_unsetenv(char **argv, char **envp);
void	parse_exit(char **argv, char **envp);
void	parse_echo(char **argv, char **envp);
char	*ft_getenv(char **envp, char *key);
char	**ft_setenv(char **envp, char *key, char *value, int override);

/*
** Helpers
*/
int		get_next_line(int fd, char **line);
void	free_split(char **array);
int		count_split(char **array);
int		envp_check(char **envp);
char	*find_path(char *name, char **envp);

/*
** Shell functions
*/
int		error(int err_num, char *arg);
int		prompt(char **envp);
void	builtin(char **argv, char **envp, t_builtin *builtins);

#endif
