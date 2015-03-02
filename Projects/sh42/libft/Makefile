#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 19:28:41 by hjeannin          #+#    #+#              #
#    Updated: 2014/06/25 18:55:24 by hjeannin         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_atoi.c ft_putchar.c ft_putstr.c \
	ft_putnbr.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strdup.c \
	ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_strnstr.c ft_putendl.c ft_strcmp.c ft_strncmp.c \
	ft_strclr.c ft_striter.c ft_strnew.c ft_memdel.c ft_memalloc.c \
	ft_strdel.c ft_strlcat.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	ft_strequ.c ft_strnequ.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_itoa.c ft_get_next_line.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

DEPS = libft.h

FLAGS = -Werror -Wall -Wextra

CFLAGS = -I./includes

all: $(NAME)

$(NAME):
	@gcc -c -O3 $(FLAGS) $(CFLAGS) $(SRC)
	@ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
