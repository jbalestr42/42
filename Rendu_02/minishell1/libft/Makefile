# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/23 13:09:52 by jbalestr          #+#    #+#              #
#    Updated: 2014/01/23 14:41:39 by jbalestr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

MAIN_TEST = https://raw.github.com/nirahiel/Maintest/master/libft/main.c

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/
SRC =	  ft_strlen.c ft_strdup.c ft_strcat.c ft_strchr.c ft_strstr.c \
	  ft_strcmp.c ft_strncmp.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	  ft_putendl.c ft_strdel.c ft_strjoin.c ft_strsub.c ft_strsplit.c \
	  ft_strrealloc.c ft_strncpy.c ft_strclr.c ft_strnew.c ft_memdel.c \
	  ft_memchr.c ft_memalloc.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@echo "-- Making library --"
	@echo " - Compiling..."
	@$(CC) $(FLAGS) -I $(HEADER) -c $(SRC) $?
	@echo " - Creating library..."
	@ar rc $(NAME) $(OBJ)
	@echo " - Optimizing..."
	@ranlib $(NAME)
	@echo "Done."

clean:
	@echo "-- Clean --"
	@echo " - Cleaning object files..."
	@/bin/rm -f $(OBJ)
	@echo "Done."

fclean: clean
	@echo "-- Full Clean --"
	@echo " - Deleting $(NAME)..."
	@/bin/rm -f $(NAME)
	@echo " - Deleting test source and binary..."
	@/bin/rm -f main_test.c
	@/bin/rm -f ./unit_test
	@echo "Done."

re: fclean all

main_test.c:
	@echo "-- Test --"
	@echo " - Getting test file..."
	@wget $(MAIN_TEST) -O main_test.c

unit_test: main_test.c $(NAME)
	@echo " - Compiling..."
	@$(CC) -I $(HEADER) main_test.c $(NAME) -o unit_test
	@echo "Done."

test: unit_test
	@echo "Lauching tests."
	@./unit_test
