/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 14:29:15 by csalmon-          #+#    #+#             */
/*   Updated: 2013/12/31 17:59:01 by csalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>
# define BUFF_SIZE 1024

void	pipex(char **av, char **ae);
char	**cut_path(char **ae);
char	*ft_strcpycat(char *s1, char const *s2);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_clines(char const *s, char c);
int		ft_ccol(char const *s, char c);
char	**ft_strsplit_fill(char const *s, char c, char **new);
char	**ft_strsplit(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr(char *str, char out, char n);
void	ft_if_function(int pipefd[2], int in_out[2], char **av, char **ae);
void	ft_else_function(int pipefd[2], int in_out[2], char **av, char **ae);
char	*search_exe(char **ae, char *to_find);
char	*ft_getpwd(char **ae);
char	**newargv(char **argv);

#endif
