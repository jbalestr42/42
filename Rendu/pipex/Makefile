# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/31 19:03:08 by jbalestr          #+#    #+#              #
#    Updated: 2013/12/31 19:06:57 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = pipex

FLAGS = -Wall -Wextra -Werror

SRC =	pipex.c \
		cmd_path.c \
		ft_strs.c \
		ft_strsplit.c \
		main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "[ \033[0;33;mCompiling $(NAME)\033[0m ]"
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "[ \033[0;32;mSuccess\033[0m ]"

clean:
	@echo "[ \033[0;33;mCleaning\033[0m ]"
	rm -f $(OBJ)

fclean: clean
	@echo "[ \033[0;31;mDeleting $(NAME)\033[0m ]"
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean
