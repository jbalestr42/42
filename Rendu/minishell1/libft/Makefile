# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/23 17:22:42 by pciavald          #+#    #+#              #
#    Updated: 2013/12/29 15:11:45 by pciavald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean re

MAIN_TEST = https://raw.github.com/nirahiel/Maintest/master/libft/main.c

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = includes/
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c \
	  ft_toupper.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_memalloc.c \
	  ft_memdel.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr_fd.c \
	  ft_putstr_fd.c ft_strclr.c ft_strdel.c ft_strequ.c ft_striter.c \
	  ft_striteri.c ft_strjoin.c ft_strmap.c ft_strmapi.c ft_strnequ.c \
	  ft_strnew.c ft_strsub.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_lstadd.c \
	  ft_lstpushback.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	  ft_lstnew.c ft_strrealloc.c ft_avladd.c ft_avladd_rotations.c \
	  ft_avldel.c ft_avlheight.c ft_avliter_inorder.c ft_avliter_inorderrev.c \
	  ft_avlnew.c ft_lstrev.c ft_lstsize.c ft_match.c ft_qsort.c
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
